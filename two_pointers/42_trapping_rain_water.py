from typing import List

"""
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
https://leetcode.com/problems/trapping-rain-water/

O(n), O(1)
"""

class Solution:
    def trap(self, height: List[int]) -> int:
        if not height:
            return 0

        l, r = 0, len(height) - 1
        leftMax, rightMax = height[l], height[r]
        res = 0
        while l < r:
            if leftMax < rightMax:
                l += 1
                leftMax = max(leftMax, height[l])
                res += leftMax - height[l]
            else:
                r -= 1
                rightMax = max(rightMax, height[r])
                res += rightMax - height[r]

        return res



if __name__ == "__main__":
    height = [0,1,0,2,1,0,1,3,2,1,2,1]
    # height = [4,2,0,3,2,5]
    # height = [2,0,2]
    print(Solution().trap(height))
