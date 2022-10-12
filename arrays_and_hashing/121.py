from typing import List

# https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
# O(n), O(n)
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0

        # initialize
        max_profit = 0
        min_price = prices[0]
        for price in prices[1:]:
            max_profit = max(price - min_price, max_profit)
            min_price = min(price, min_price)
        return max_profit


if __name__ == "__main__":
    prices = [7, 1, 5, 3, 6, 4]
    print(Solution().maxProfit(prices))
