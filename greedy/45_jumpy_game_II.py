from typing import List

"""
You are given a 0-indexed array of integers nums of length n. You are initially
positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index
i. In other words, if you are at nums[i], you can jump to any nums[i + j]
where:

    0 <= j <= nums[i] and i + j < n Return the minimum number of jumps to reach
    nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].
https://leetcode.com/problems/jump-game-ii/description/
O(n), O(1)
"""

class Solution:
    def jump(self, nums: List[int]) -> int:
        res = 0
        l, r = 0, 0
        while r < (len(nums) - 1):
            farthest = 0 # reachable farthest index
            for i in range(l, r + 1):
                farthest = max(farthest, i + nums[i])

            l = r + 1
            r = farthest
            res += 1
        return res



if __name__ == "__main__":
    # nums = [2,3,1,1,4]
    nums = [2,3,0,1,4]
    print(Solution().jump(nums))
