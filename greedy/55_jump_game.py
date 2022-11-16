from typing import List

"""
You are given an integer array nums. You are initially positioned at the
array's first index, and each element in the array represents your maximum jump
length at that position.

Return true if you can reach the last index, or false otherwise.

https://leetcode.com/problems/jump-game/
O(n), O(1)
"""


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        goal = len(nums) - 1
        for i in range(len(nums) - 1, -1, -1):
            if i + nums[i] >= goal:
                goal = i

        return goal == 0


if __name__ == "__main__":
    nums = [2, 3, 1, 1, 4]
    print(Solution().canJump(nums))
