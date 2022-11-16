#include <vector>
#include <iostream>
using namespace std;

/* Given an integer array nums, find the 
subarray which has the largest sum and return its sum.
https://leetcode.com/problems/maximum-subarray/
O(n), O(1) */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currSum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (currSum < 0) {
                currSum = 0;
            }
            currSum += nums[i];
            maxSum = max(currSum, maxSum);
        }
        return maxSum;
    }
};


int main (int argc, char *argv[])
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << Solution().maxSubArray(nums) << endl;
    return 0;
}
