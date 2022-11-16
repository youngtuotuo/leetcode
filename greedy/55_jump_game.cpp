#include <iostream>
#include <vector>
using namespace std;

/* You are given an integer array nums. You are initially positioned at the
array's first index, and each element in the array represents your maximum jump
length at that position.

Return true if you can reach the last index, or false otherwise.

https://leetcode.com/problems/jump-game/
O(n), O(1) */

class Solution {
  public:
    bool canJump(vector<int> &nums) {
        int goal = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i + nums[i] >= goal) {
                goal = i;
            }
        }
        return (goal == 0);
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << Solution().canJump(nums) << endl;
    return 0;
}
