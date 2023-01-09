#include <iostream>
#include <vector>
using namespace std;

/* There is an integer array nums sorted in ascending order (with distinct
values).

Prior to being passed to your function, nums is possibly rotated at an unknown
pivot index k (1 <= k < nums.length) such that the resulting array is

[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]

(0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and
become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return
the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

https://leetcode.com/problems/search-in-rotated-sorted-array/

O(log n), O(1)
*/

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int l(0), r(nums.size() - 1);
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (target == nums[m]) {
                return m;
            }

            if (nums[m] >= nums[l]) {
                if (target > nums[m] || target < nums[l]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            } else {
                if (target < nums[m] || target > nums[r]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
        }
        return -1;
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums({4, 5, 6, 7, 0, 1, 2});
    int target = 4;
    cout << Solution().search(nums, target) << endl;
    return 0;
}
