#include <iostream>
#include <vector>
using namespace std;

/* Given a binary array nums and an integer k, return the maximum number of
consecutive 1's in the array if you can flip at most k 0's.

https://leetcode.com/problems/max-consecutive-ones-iii/

O(n), O(1) */

class Solution {
public:
    int logestOnes(vector<int> &nums, int k) {
        int res = 0, l = 0, curr = 0, countFlip = 0;
        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] == 0) {
                countFlip += 1;
            }
            if (nums[r] == 1 | countFlip <= k){
                curr++;
                res = max(curr, res);
            }
            while (nums[r] == 0 && countFlip > k) {
                if (nums[l] == 0) {
                    countFlip--;
                } else if (nums[l] == 1) {
                    curr--;
                }
                l++;
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    int k = 3;
    cout << Solution().logestOnes(nums, k) << endl;
    return 0;
}
