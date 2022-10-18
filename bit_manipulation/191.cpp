#include <iostream>
using namespace std;

// https://leetcode.com/problems/number-of-1-bits/
// O(32), (1)
class Solution {
public:
  int hammingWeight(uint32_t &n) {
    int res = 0;
    while (n != 0) {
      res += n % 2;
      n = n >> 1;
    }
    return res;
  }
  int another(uint32_t &n) {
    int res = 0;
    while (n != 0) {
      n &= (n - 1);
      res += 1;
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  uint32_t n = 0b00000000000000000000000000001011;
  // cout << Solution().hammingWeight(n) << endl;
  cout << Solution().another(n) << endl;
  return 0;
}
