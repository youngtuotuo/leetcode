from typing import List

# https://leetcode.com/problems/product-of-array-except-self/
# O(n), O(1)
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        ans = [1 for _ in range(len(nums))]
        # right to left
        for i in range(len(nums) - 1):
            ans[i + 1] = nums[i] * ans[i]

        # left to right
        post = 1
        for i in range(len(nums) - 1, -1, -1):
            ans[i] *= post
            post *= nums[i]
        return ans



if __name__ == "__main__":
    nums = [1, 2, 3, 4]
    print(Solution().productExceptSelf(nums))
