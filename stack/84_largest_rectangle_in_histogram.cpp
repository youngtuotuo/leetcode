#include <iostream>
#include <vector>
using namespace std;

/* Given an array of integers heights representing the histogram's bar height
where the width of each bar is 1, return the area of the largest rectangle in
the histogram.

https://leetcode.com/problems/largest-rectangle-in-histogram/
O(n), O(n) */

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int res = 0;
        vector<pair<int, int>> s;
        int n = heights.size();
        for (int i = 0; i < n; i++) {
            int h = heights[i];
            int start = i;
            while (!s.empty() && s.back().second > h) {
                int index = s.back().first;
                int height = s.back().second;
                s.pop_back();
                res = max(res, height * (i - index));
                start = index;
            }
            s.push_back({start, h});
        }
        for (int i = 0; i < s.size(); i++) {
            res = max(res, s[i].second * (n - s[i].first));
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << Solution().largestRectangleArea(heights) << endl;
    return 0;
}
