"""
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

https://leetcode.com/problems/happy-number/
O(n), O(1)
"""


class Solution:
    def isHappy(self, n: int) -> bool:
        slow, fast = n, self.sumSquaresDigits(n)

        while slow != fast:
            fast = self.sumSquaresDigits(fast)
            fast = self.sumSquaresDigits(fast)
            slow = self.sumSquaresDigits(slow)

        return fast == 1

    def sumSquaresDigits(self, n: int) -> int:
        output = 0
        while n:
            output += (n % 10) ** 2
            n //= 10
        return output


if __name__ == "__main__":
    n = 19
    print(Solution().isHappy(n))
