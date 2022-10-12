#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// O(n), O(n)
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
