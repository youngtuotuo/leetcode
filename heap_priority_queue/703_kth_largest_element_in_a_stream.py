from typing import List
import heapq


# https://leetcode.com/problems/kth-largest-element-in-a-stream/
# O(n log n + m log k), n = length of nums, m = add calls
# O(n)
class KthLargest:
    def __init__(self, k: int, nums: List[int]):
        self.minHeap, self.k = nums, k
        heapq.heapify(self.minHeap)
        while len(self.minHeap) > k:
            heapq.heappop(self.minHeap)

    def add(self, val: int) -> int:
        heapq.heappush(self.minHeap, val)
        if len(self.minHeap) > self.k:
            heapq.heappop(self.minHeap)
        return self.minHeap[0]

if __name__ == "__main__":
    k = 3
    nums = [4, 5, 8, 2]
    kl = KthLargest(k, nums)
    print(kl.add(3))
    print(kl.add(5))
    print(kl.add(10))
    print(kl.add(9))
    print(kl.add(4))
    
