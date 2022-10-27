from typing import List

"""
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

https://leetcode.com/problems/single-number/
O(n), O(1)
"""
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        res = 0  # n ^ 0 = n
        for n in nums:
            res = n ^ res
        return res


if __name__ == "__main__":
    nums = [4, 1, 2, 1, 2]
    print(Solution().singleNumber(nums))
