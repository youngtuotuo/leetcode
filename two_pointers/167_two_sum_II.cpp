#include <iostream>
#include <vector>
using namespace std;


/* Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
O(n), O(1)
*/

class Solution {
public:
  vector<int> twoSum(vector<int>& numbders, int target) {
    int l = 0, r = numbders.size() - 1;
    vector<int> ans;
    while (l < r) {
      int curSum = numbders[l] + numbders[r];
      if (curSum > target) {
        r--;
      } else if (curSum < target) {
        l++;
      } else {
        ans = {++l, ++r};
        return ans;
      }
    }
    return ans;
  }
};


int main (int argc, char *argv[])
{
  vector<int> numbers = {2, 7, 11, 15};
  int target = 9;
  for (int i: Solution().twoSum(numbers, target)) {
    cout << i << ' ';
  }
  cout << endl;
  return 0;
}
