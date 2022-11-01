#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
  Given an array of integers nums and an integer target, return indices of the
  two numbers such that they add up to target.

  You may assume that each input would have exactly one solution, and you may
  not use the same element twice.

  You can return the answer in any order.
  https://leetcode.com/problems/two-sum/
  O(n), O(n)
*/

class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> ans;
        unordered_map<int, int> pair;
        for (int i = 0; i < nums.size(); i++) {
            if (pair.find(target - nums[i]) != pair.end()) {
                ans = {pair[target - nums[i]], i};
                return ans;
            } else {
                pair[nums[i]] = i;
            }
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = Solution().twoSum(nums, target);
    for (int i : ans) {
        cout << i << ", ";
    }
    cout << endl;
    return 0;
}
