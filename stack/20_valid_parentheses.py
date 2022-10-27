"""
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.
# https://leetcode.com/problems/valid-parentheses/
# O(n), O(n)
"""

class Solution:
    def isValid(self, s: str) -> bool:
        left = []
        pair = {"(": ")", "[": "]", "{": "}"}
        for p in s:
            if p in pair:
                left.append(p)
            else:
                if len(left) == 0 or pair[left.pop()] != p:
                    return False
        return len(left) == 0


if __name__ == "__main__":
    s = "]"
    print(Solution().isValid(s))
