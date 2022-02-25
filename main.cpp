#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol487;

/*
 Example 1:
 Input: [1,0,1,1,0]
 Output: 4
 Explanation: Flip the first zero will get the the maximum number of consecutive 1s.
 After flipping, the maximum number of consecutive 1s is 4.
*/
tuple<vector<int>, int>
testFixture1()
{
  return make_tuple(vector<int>({1, 0, 1, 1, 0, 1}), 4);
}

tuple<vector<int>, int>
testFixture2()
{
  return make_tuple(vector<int>({1, 1, 1, 1, 1, 1}), 6);
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - exepct to see " << to_string(get<1>(f)) << endl;
  auto result = Solution::findOnes(get<0>(f));
  cout << "result: " << to_string(result) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Test 2 - exepct to see " << to_string(get<1>(f)) << endl;
  auto result = Solution::findOnes(get<0>(f));
  cout << "result: " << to_string(result) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}