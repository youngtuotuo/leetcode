# https://leetcode.com/problems/reverse-bits/
# O(1), O(1)


class Solution:
    def reverseBits(self, n: int) -> int:
        res = 0
        for i in range(32):
            bit = (n >> i) & 1
            res |= bit << (31 - i)
        return res


if __name__ == "__main__":
    n = 0b00000010100101000001111010011100
    print(Solution().reverseBits(n))
