"""
Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

Note:

Note that in some languages, such as Java, there is no unsigned integer type. In this case, the input will be given as a signed integer type. It should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 3, the input represents the signed integer. -3.

https://leetcode.com/problems/number-of-1-bits/
O(32), (1)
"""


class Solution:
    def hammingWeight(self, n: int) -> int:
        res = 0
        while n:
            res += n % 2
            n = n >> 1
        return res

    def another(self, n: int) -> int:
        res = 0
        while n:
            n &= n - 1
            res += 1
        return res


if __name__ == "__main__":
    n = 0b00000000000000000000000000001011
    # print(Solution().hammingWeight(n))
    print(Solution().another(n))
