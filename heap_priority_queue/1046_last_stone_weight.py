from typing import List
import heapq

"""
You are given an array of integers stones where stones[i] is the weight of the
ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two
stones and smash them together. Suppose the heaviest two stones have weights x
and y with x <= y. The result of this smash is:

    If x == y, both stones are destroyed, and If x != y, the stone of weight x
    is destroyed, and the stone of weight y has new weight y - x. At the end of
    the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left,
return 0.
https://leetcode.com/problems/last-stone-weight/
O(nlog n), O(n)
"""


class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones = [-s for s in stones]
        heapq.heapify(stones)
        while len(stones) > 1:
            first = heapq.heappop(stones)
            second = heapq.heappop(stones)
            if second > first:
                heapq.heappush(stones, first - second)
        stones.append(0)
        return abs(stones[0])


if __name__ == "__main__":
    stones = [2, 7, 4, 1, 8, 1]
    print(Solution().lastStoneWeight(stones))
