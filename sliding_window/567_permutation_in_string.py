"""
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

https://leetcode.com/problems/permutation-in-string/
O(n), O(26)
"""



class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False
        
        count = [0] * 26
        for i in range(len(s1)):
            count[ord(s1[i]) - ord('a')] += 1
            count[ord(s2[i]) - ord('a')] -= 1
        if self.isPermutation(count):
            return True

        for i in range(len(s1), len(s2)):
            count[ord(s2[i]) - ord('a')] -= 1
            count[ord(s2[i - len(s1)]) - ord('a')] += 1
            if self.isPermutation(count):
                return True

        return False

    def isPermutation(self, count):
        for c in count:
            if c != 0:
                return False

        return True


if __name__ == "__main__":
    s1 = "ab"
    s2 = "eidbaooo"
    print(Solution().checkInclusion(s1, s2))
