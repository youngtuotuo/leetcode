import heapq
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

O(n^2), O(n)
"""


class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        N = len(points)
        adj = {i: [] for i in range(N)}  # i: list of [cost, node]
        for i in range(N):
            x1, y1 = points[i]
            for j in range(i + 1, N):
                x2, y2 = points[j]
                dist = abs(x1 - x2) + abs(y1 - y2)
                adj[i].append([dist, j])
                adj[j].append([dist, i])

        # Prim's
        res = 0
        visit = set()
        minH = [[0, 0]]  # [cost, node]
        while len(visit) < N:
            cost, i = heapq.heappop(minH)
            if i in visit:
                continue
            res += cost
            visit.add(i)
            for neiCost, nei in adj[i]:
                if nei not in visit:
                    heapq.heappush(minH, [neiCost, nei])
        return res

    def another(self, points: List[List[int]]) -> int:
        N = len(points)
        edgesUsed = 0
        inMST = [0 for _ in range(N)]
        minDist = [float('inf') for _ in range(N)]
        minDist[0] = 0
        res = 0
        while edgesUsed < N:
            currMinEdge = float("inf")
            currNode = -1
            for i in range(N):
                if not inMST[i] and currMinEdge > minDist[i]:
                    currMinEdge = minDist[i]
                    currNode = i

            res += currMinEdge
            edgesUsed += 1
            inMST[currNode] = 1

            for i in range(N):
                cost = abs(points[currNode][0] - points[i][0]) + abs(
                    points[currNode][1] - points[i][1]
                )

                if not inMST[i] and minDist[i] > cost:
                    minDist[i] = cost
        return res


if __name__ == "__main__":
    points = [[0, 0], [2, 2], [3, 10], [5, 2], [7, 0]]
    # print(Solution().minCostConnectPoints(points))
    print(Solution().another(points))
