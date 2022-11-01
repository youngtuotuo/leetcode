from typing import List


"""
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

https://leetcode.com/problems/missing-number/

O(n), O(1)
"""


class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        res = len(nums)
        for i in range(res):
            res += i - nums[i]

        return res


if __name__ == "__main__":
    nums = [0, 1]
    print(Solution().missingNumber(nums))
