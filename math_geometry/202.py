# https://leetcode.com/problems/happy-number/
# O(n), O(1)


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
