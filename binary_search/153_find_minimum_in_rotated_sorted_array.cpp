#include <iostream>
#include <vector>
using namespace std;

/* Suppose an array of length n sorted in ascending order is rotated between 1 and
n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times. [0,1,2,4,5,6,7] if it was
rotated 7 times. Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in
the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum
element of this array.

You must write an algorithm that runs in O(log n) time.
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
O(log n), O(1)
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l(0), r(nums.size() - 1);
        int res(nums[0]);

        while (l <= r) {
            if (nums[l] < nums[r]) {
                res = min(res, nums[1]);
                break;
            }
            int mid = l + (r - l) / 2;
            res = min(res, nums[mid]);

            if (nums[mid] >= nums[l]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }
};


int main (int argc, char *argv[])
{
    vector<int> nums = {3,4,5,1,2};
    cout << Solution().findMin(nums) << endl;
    return 0;
}
