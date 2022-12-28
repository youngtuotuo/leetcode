#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/* Given an array of integers temperatures represents the daily temperatures,
return an array answer such that answer[i] is the number of days you have to
wait after the ith day to get a warmer temperature. If there is no future day
for which this is possible, keep answer[i] == 0 instead.

https://leetcode.com/problems/daily-temperatures/
O(n), O(n) */

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        int n = temperatures.size();

        stack<pair<int, int>> stk;
        vector<int> result(n);

        for (int i = 0; i < n; i++) {
            int currDay = i;
            int currTemp = temperatures[i];

            while (!stk.empty() && stk.top().second < currTemp) {
                int prevDay = stk.top().first;
                stk.pop();

                result[prevDay] = currDay - prevDay;
            }

            stk.push({currDay, currTemp});
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    for (int i : Solution().dailyTemperatures(temperatures)) {
        cout << i << ", ";
    }
    return 0;
}
