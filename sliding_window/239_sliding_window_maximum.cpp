#include <deque>
#include <iostream>
#include <vector>
using namespace std;

/* You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.
https://leetcode.com/problems/sliding-window-maximum/
O(n), O(n) */


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = 0, r = 0;
        deque<int> q;
        vector<int> output;
        while (r < nums.size()) {
            while (!q.empty() && nums[r] > nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(r);

            if (l > q.front()) {
                q.pop_front();
            }

            if (r + 1 >= k) {
                output.push_back(nums[q.front()]);
                l++;
            }
            r++;
        }
        return output;
    }
};


int main (int argc, char *argv[])
{
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    for (int n: Solution().maxSlidingWindow(nums, k)) {
        cout << n << ", ";
    }
    cout << endl;
    return 0;
}
