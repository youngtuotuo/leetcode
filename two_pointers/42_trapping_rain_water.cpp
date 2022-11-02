#include <vector>
#include <iostream>
using namespace std;


/* Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
https://leetcode.com/problems/trapping-rain-water/

O(n), O(1) */

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int leftMax = height[l], rightMax = height[r];
        int res = 0;
        while (l < r) {
            if (leftMax < rightMax) {
                l++;
                leftMax = max(leftMax, height[l]);
                res += leftMax - height[l];
            } else {
                r--;
                rightMax = max(rightMax, height[r]);
                res += rightMax - height[r];
            }
        }
        return res;
    }
};
;
int main (int argc, char *argv[])
{
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << Solution().trap(height) << endl;
    return 0;
}
