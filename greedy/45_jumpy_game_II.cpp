#include <vector>
#include <iostream>
using namespace std;

/* You are given a 0-indexed array of integers nums of length n. You are initially
positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index
i. In other words, if you are at nums[i], you can jump to any nums[i + j]
where:

    0 <= j <= nums[i] and i + j < n Return the minimum number of jumps to reach
    nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].
https://leetcode.com/problems/jump-game-ii/description/
O(n), O(1) */


class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0;
        int l = 0, r = 0;
        while (r < (nums.size() - 1)) {
            int farthest = 0;
            for (int i = l; i < r + 1; i++) {
                farthest = max(farthest, i + nums[i]);
            }
            l = r + 1;
            r = farthest;
            res += 1;
        }
        return res;
    }
};


int main (int argc, char *argv[])
{
    vector<int> nums = {2,3,1,1,4};
    cout << Solution().jump(nums) << endl;
    return 0;
}
