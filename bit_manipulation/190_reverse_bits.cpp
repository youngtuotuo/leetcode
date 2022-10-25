#include <iostream>
using namespace std;

// https://leetcode.com/problems/reverse-bits/
// O(1), O(1)
class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    for (uint32_t i = 0; i < 32; i++) {
      uint32_t bit = (n >> i) & 1;
      res |= (bit << (31 - i));
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  uint32_t n = 0b00000010100101000001111010011100;
  cout << Solution().reverseBits(n) << endl;
  return 0;
}
