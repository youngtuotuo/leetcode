#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/binary-search/
// O(log n), O(1)
class Solution {
public:
  int search(vector<int> &nums, int target) {
    int l = 0;
    int r = nums.size() - 1;
    while (l <= r) {
      int m = l + ((r - l) / 2);
      if (nums[m] > target) {
        r = m - 1;
      } else if (nums[m] < target) {
        l = m + 1;
      } else {
        return m;
      }
    }
    return -1;
  }
};

int main(int argc, char *argv[]) {
  vector<int> nums = {-1, 0, 3, 5, 9, 12};
  int target = 9;
  int ans = Solution().search(nums, target);
  cout << ans << endl;

  return 0;
}
