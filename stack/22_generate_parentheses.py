from typing import List

"""
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

https://leetcode.com/problems/generate-parentheses/

O(2^n), O(n)
"""

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        
        def backtrack(openN, closedN, string):
            if openN == closedN == n:
                res.append(string)
                return

            if openN < n:
                backtrack(openN + 1, closedN, string + '(')
            if closedN < openN:
                backtrack(openN, closedN + 1, string + ')')


        backtrack(0, 0, '')
        return res



if __name__ == "__main__":
    print(Solution().generateParenthesis(3))
