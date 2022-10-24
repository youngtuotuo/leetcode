from typing import List


# https://leetcode.com/problems/plus-one/
# O(n), O(1)
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        for i in range(len(digits) - 1, -1, -1):
            if digits[i] < 9:
                digits[i] += 1
                return digits
            digits[i] = 0
        digits[0] = 1
        digits.append(0)
        return digits


if __name__ == "__main__":
    digits = [9, 9]
    print(Solution().plusOne(digits))
