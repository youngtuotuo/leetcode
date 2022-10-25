from typing import List

# https://leetcode.com/problems/single-number/
# O(n), O(1)
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        res = 0  # n ^ 0 = n
        for n in nums:
            res = n ^ res
        return res


if __name__ == "__main__":
    nums = [4, 1, 2, 1, 2]
    print(Solution().singleNumber(nums))
