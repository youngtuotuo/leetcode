#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/* Given an integer array nums,
return all the triplets [nums[i], nums[j], nums[k]]
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

https://leetcode.com/problems/3sum/
O(nlon n) + O(n^2)
O(n) */

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] > 0) {
                break;
            }

            if (i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                int threeSum = nums[i] + nums[l] + nums[r];
                if (threeSum > 0) {
                    r--;
                } else if (threeSum < 0) {
                    l++;
                } else {
                    res.push_back({nums[i], nums[l], nums[r]});

                    while (l < r && nums[l] == nums[l + 1]) {
                        l++;
                    }
                    l++;
                }
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    // vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<int> nums = {-1, 0, 1, 0};
    for (vector<int> v : Solution().threeSum(nums)) {
        cout << '[';
        for (int i : v) {
            cout << i << ", ";
        }
        cout << "], ";
    }
    cout << endl;
    return 0;
}
