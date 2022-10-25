from typing import List


# https://leetcode.com/problems/min-cost-climbing-stairs/
# O(n - 3), O(n + 1)
class Solution:
    def minCostClimbingstairs(self, cost: List[int]) -> int:
        cost.append(0)
        for i in range(len(cost) - 3, -1, -1):
            cost[i] += min(cost[i + 1], cost[i + 2])
        return min(cost[0], cost[1])


if __name__ == "__main__":
    cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
    print(Solution().minCostClimbingstairs(cost))
