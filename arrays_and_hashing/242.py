# https://leetcode.com/problems/valid-anagram/
# O(n), O(26)


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        countS, countT = {}, {}
        for i in range(len(s)):
            countS[s[i]] = 1 + countS.get(s[i], 0)
            countT[t[i]] = 1 + countT.get(t[i], 0)
        return countS == countT

    def isAnagram2(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        count = [0 for _ in range(26)]

        for c in s:
            count[ord(c) - ord("a")] += 1

        for c in t:
            count[ord(c) - ord("a")] -= 1
            if count[ord(c) - ord("a")] < 0:
                return False

        return True
