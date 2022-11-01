#include <iostream>
#include <vector>
using namespace std;

/*
Given an array nums containing n distinct numbers in the range [0, n], return
the only number in the range that is missing from the array.

https://leetcode.com/problems/missing-number/
O(n), O(1)
*/

class Solution {
  public:
    int missingNumber(vector<int> &nums) {
        int res = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            res += (i - nums[i]);
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums = {3, 0, 1};
    cout << Solution().missingNumber(nums) << endl;
    return 0;
}
