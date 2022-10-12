# https://leetcode.com/problems/contains-duplicate/
# O(n), O(n)


from typing import List


class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        collect = dict()
        for num in nums:
            if num in collect:
                collect[num] += 1
                if collect[num] >= 2:
                    return True
            else:
                collect[num] = 1
        return False
