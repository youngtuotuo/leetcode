from typing import List

"""
Given an integer array nums, find the 
subarray which has the largest sum and return its sum.
https://leetcode.com/problems/maximum-subarray/
O(n), O(1)
"""


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxSum = nums[0]
        curSum = nums[0]
        for n in nums[1:]:
            if curSum < 0:
                curSum = 0
            curSum += n
            # the above 3 lines equiv to
            # curSum = max(n, curSum + n)
            maxSum = max(curSum, maxSum)

        return maxSum


if __name__ == "__main__":
    nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
    print(Solution().maxSubArray(nums))
