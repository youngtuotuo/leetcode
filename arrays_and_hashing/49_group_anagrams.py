from typing import List
from collections import defaultdict

"""
    Given an array of strings strs, group the anagrams together. You can return the answer in any order.

    An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
    https://leetcode.com/problems/group-anagrams/
    O(m * n), m is the number of strings, n is the average length of the strings we get
"""


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # encode each str into a key, anagram will give the same key
        res = defaultdict(list)

        for s in strs:
            count = [0 for _ in range(26)]
            for c in s:
                count[ord(c) - ord("a")] += 1

            res[tuple(count)].append(s)

        return res.values()


if __name__ == "__main__":
    strs = ["eat", "tea", "tan", "ate", "nat", "bat"]

    print(Solution().groupAnagrams(strs))
