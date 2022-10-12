from typing import List
from collections import defaultdict

# https://leetcode.com/problems/group-anagrams/
# O(m * n), m is the number of strings, n is the average length of the strings we get
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
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
