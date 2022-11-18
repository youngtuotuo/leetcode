from typing import List

"""
You are given an array points representing integer coordinates of some points
on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan
distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute
value of val.

Return the minimum cost to make all points connected. All points are connected
if there is exactly one simple path between any two points.
https://leetcode.com/problems/min-cost-to-connect-all-points/
"""

class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        ...




if __name__ == "__main__":
    points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
    print(Solution().minCostConnectPoints(points))
