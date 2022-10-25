#include <iostream>
#include <vector>
using namespace std;


// https://leetcode.com/problems/product-of-array-except-self/
// O(n), O(1)
class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& nums) {
      vector<int> ans(nums.size(), 1);
      // left to right
      for (int i = 0; i < nums.size() - 1; i++) {
        ans[i + 1] = nums[i] * ans[i];
      }
      // right to left
      int post = 1;
      for (int i = nums.size() - 1; i >= 0; i--) {
        ans[i] *= post;
        post *= nums[i];
      }

      return ans;
    }
};


int main (int argc, char *argv[])
{
  vector<int> nums = {1,2,3,4};
  for (int n: Solution().productExceptSelf(nums)) {
    cout << n << ' ';
  }
  cout << endl;
  return 0;
}
