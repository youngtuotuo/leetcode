#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/single-number/
// O(n), O(1)

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
