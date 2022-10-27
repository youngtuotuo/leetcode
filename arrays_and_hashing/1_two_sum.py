from typing import List

"""
    Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

    You may assume that each input would have exactly one solution, and you may not use the same element twice.

    You can return the answer in any order.
    https://leetcode.com/problems/two-sum/
    O(n), O(n)
"""


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        if not nums:
            return

        pair = {}
        for index, num in enumerate(nums):
            if target - num in pair:
                return [pair[target - num], index]
            else:
                pair[num] = index


if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 9
    print(Solution().twoSum(nums, target))
