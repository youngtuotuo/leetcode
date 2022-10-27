from typing import List


"""
    Given an integer array nums, return true if any value appears at least twice in the array,
    and return false if every element is distinct.
    https://leetcode.com/problems/contains-duplicate/
    O(n), O(n)
"""


class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        collect = set()
        for num in nums:
            if num in collect:
                return True
            else:
                collect.add(num)
        return False


if __name__ == "__main__":
    nums = [1, 2, 3, 1]
    print(Solution().containsDuplicate(nums))
