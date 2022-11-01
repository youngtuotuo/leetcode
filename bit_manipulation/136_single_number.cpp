#include <iostream>
#include <vector>
using namespace std;

/*
Given a non-empty array of integers nums, every element appears twice except for
one. Find that single one.

You must implement a solution with a linear runtime complexity and use only
constant extra space.

https://leetcode.com/problems/single-number/
O(n), O(1)
*/

class Solution {
  public:
    int singleNumber(vector<int> &nums) {
        int res = 0;
        for (int num : nums) {
            res = res ^ num;
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << Solution().singleNumber(nums) << endl;
    return 0;
}
