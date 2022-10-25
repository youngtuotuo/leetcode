from typing import List


# https://leetcode.com/problems/two-sum/
# O(n), O(n)
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
