from typing import List
import heapq

"""
    Given an integer array nums and an integer k, return the k most frequent elements.
    You may return the answer in any order.
    https://leetcode.com/problems/top-k-frequent-elements/
"""


class Solution:
    # O(n), O(n)
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = {}
        for num in nums:
            count[num] = 1 + count.get(num, 0)

        freq = [[] for _ in range(len(nums))]
        for n, c in count.items():
            freq[c - 1].append(n)

        res = []
        for i in range(len(freq) - 1, -1, -1):
            for n in freq[i]:
                res.append(n)
                if len(res) == k:
                    return res

    # O(n log k), O(n + k)
    def another(self, nums: List[int], k: int) -> List[int]:
        count = dict()
        for num in nums:
            count[num] = 1 + count.get(num, 0)

        minHeap = []
        heapq.heapify(minHeap)
        for num, freq in count.items():
            heapq.heappush(minHeap, (freq, num))
            if len(minHeap) > k:
                heapq.heappop(minHeap)

        res = []
        while len(minHeap):
            res.append(minHeap[0][1])
            heapq.heappop(minHeap)
        return res


if __name__ == "__main__":
    nums = [1, 1, 1, 2, 2, 3]
    k = 2
    print(Solution().topKFrequent(nums, k))
    print(Solution().another(nums, k))
