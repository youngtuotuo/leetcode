#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;




/*

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

https://leetcode.com/problems/longest-consecutive-sequence/
O(n), O(n)

*/
class Solution {
  public:
    int longestConsecutive(vector<int>& nums) {
      unordered_set<int> s(nums.begin(), nums.end());
      int longest = 0;
      for (int n: nums) {
        if (s.find(n - 1) == s.end()) {
          int length = 1;
          while (s.find(n + length) != s.end()) {
            length++;
          }
          longest = max(length, longest);
        }
      }
      return longest;
    }
};



int main (int argc, char *argv[])
{
  vector<int> nums = {9,1,4,7,3,-1,0,5,8,-1,6};
  cout << Solution().longestConsecutive(nums) << endl;
  return 0;
}
