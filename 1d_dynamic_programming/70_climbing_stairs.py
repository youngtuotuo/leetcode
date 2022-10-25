# https://leetcode.com/problems/climbing-stairs/
# O(n-1), O(1)
class Solution:
    def climbStairs(self, n: int) -> int:
        one, two = 1, 1
        for i in range(n-1):
            one, two = one + two, one

        return one



if __name__ == "__main__":
    n = 3
    print(Solution().climbStairs(n))
