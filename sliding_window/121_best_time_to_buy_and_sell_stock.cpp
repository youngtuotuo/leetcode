#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
O(n), O(n)
*/
class Solution {
  public:
    int maxProfit(vector<int>& prices) {
      if (prices.empty()) {
        return 0;
      }
      int max_profit = 0;
      int min_price = prices[0];
      for (int i = 1; i < prices.size(); i++) {
        min_price = min(prices[i], min_price);
        max_profit = max(prices[i] - min_price, max_profit);
      }
      return max_profit;
    }
};


int main() {
  vector<int> price{7, 1, 5, 3, 6, 4};
  int ans{Solution().maxProfit(price)};
  cout << "ans= " << ans << "\n";
  return 0;
}
