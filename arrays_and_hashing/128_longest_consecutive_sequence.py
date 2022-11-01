from typing import List


"""
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

https://leetcode.com/problems/longest-consecutive-sequence/
O(n), O(n)
"""


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        numSet = set(nums)
        longest = 0

        for n in nums:
            if (n - 1) not in numSet:
                length = 0
                while (n + length) in numSet:
                    length += 1
                longest = max(length, longest)

        return longest


if __name__ == "__main__":
    # nums = [100,4,200,1,3,2]
    # nums = [0,3,7,2,5,8,4,6,0,1]
    # nums = [1,2,0,1]
    nums = [9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6]
    print(Solution().longestConsecutive(nums))
