#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// https://leetcode.com/problems/contains-duplicate/
// O(n), O(n)
class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    unordered_set<int> collect;
    for (int num : nums) {
      if (collect.find(num) != collect.end()) {
        return true;
      } else {
        collect.insert(num);
      }
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  vector<int> nums = {1, 2, 3, 1};
  bool ans = Solution().containsDuplicate(nums);
  cout << ans << endl;
  return 0;
}
