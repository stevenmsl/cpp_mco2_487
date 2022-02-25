#include "solution.h"
#include "util.h"
#include <queue>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <sstream>
#include <functional>

using namespace sol487;
using namespace std;

/*takeaways
  - the range of consecutive ones that can be covered by flipping
    at most 1 zero is shown below:
     0[....0.....]0
    - the range is started at index(previous 0) + 1 and ended
      once you encountered the next 0
    - in this range when you count how many 1's are there,
      you need to included zero as 1 as well as we will
      flip it anyway
*/

int Solution::findOnes(vector<int> &input)
{
  /* you can at most flip k 0 */
  auto result = 0, k = 1;
  /* the input numbers come in one by one as an infinite stream
     - this means in-between two zeros there might be a lot
       of 1's and we can't store all of them in the memory. We
       might no longer have access to the index of the previous
       zeros.
     - we need to remember the index of each 0 we encountered
  */
  auto zIndxs = queue<int>();

  int start = 0;

  /*
    - given a 0, you need to scan through the whole range
      it can cover. Use [1,0,1,1,0] as an example
      - for the first 0 the range is from index 0 to index 3
      - you need to count it as well when you scan
        through the first 0
      - you know the range is covered when you
        encountered the second 0
  */

  for (auto i = 0; i < (int)input.size(); i++)
  {
    if (input[i] == 0)
      zIndxs.push(i);
    if (zIndxs.size() > k)
    {
      /*
        - we are done for this range;
        - adjust the start
      */
      start = zIndxs.front() + 1;
      zIndxs.pop();
    }
    /*
      - count how many 1's we have accumulated so far
      - treat 0 as one as we are going to flip it anyway
      - we will start a new range if the start is updated
        when enough zeros is accumulated
    */
    result = max(i - start + 1, result);
  }

  return result;
}