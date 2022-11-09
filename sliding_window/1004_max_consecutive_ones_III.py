from typing import List


"""
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

https://leetcode.com/problems/max-consecutive-ones-iii/

O(n), O(1)
"""


class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        l = 0
        flipCount, res = 0, 0
        curr = 0
        for r in range(len(nums)):
            if nums[r] == 0:
                flipCount += 1

            if nums[r] == 1 or flipCount <= k:
                curr += 1
                res = max(curr, res)

            while nums[r] == 0 and flipCount > k:
                if nums[l] == 0:
                    flipCount -= 1
                elif nums[l] == 1:
                    curr -= 1
                l += 1

        return res


if __name__ == "__main__":
    # nums = [1,1,1,0,0,0,1,1,1,1,0]
    nums = [0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1]
    k = 3
    print(Solution().longestOnes(nums, k))
