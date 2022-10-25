# https://leetcode.com/problems/number-of-1-bits/
# O(32), (1)
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
