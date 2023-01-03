from typing import List

"""
Given an array of integers heights representing the histogram's bar height
where the width of each bar is 1, return the area of the largest rectangle in
the histogram.

https://leetcode.com/problems/largest-rectangle-in-histogram/
O(n), O(n)
"""


class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        res = 0
        stack = []
        for i, h in enumerate(heights):
            start = i
            while stack and stack[-1][1] > h:
                index, height = stack.pop()
                res = max(res, height * (i - index))
                start = index
            stack.append((start, h))

        for i, h in stack:
            res = max(res, h * (len(heights) - i))
        return res


if __name__ == "__main__":
    heights = [2, 1, 5, 6, 2, 3]
    print(Solution().largestRectangleArea(heights))
