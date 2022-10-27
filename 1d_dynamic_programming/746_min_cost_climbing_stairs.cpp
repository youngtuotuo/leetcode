#include <iostream>
#include <vector>
using namespace std;


/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

https://leetcode.com/problems/min-cost-climbing-stairs/
O(n - 3), O(n + 1)
*/

class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
      cost.push_back(0);
      for (int i = cost.size() - 3; i >= 0; i--) {
        cost[i] += min(cost[i + 1], cost[i + 2]);
      }
      return min(cost[0], cost[1]);
    }
};


int main (int argc, char *argv[])
{
  vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
  cout << Solution().minCostClimbingStairs(cost) << endl;
  return 0;
}
