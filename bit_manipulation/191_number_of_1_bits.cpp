#include <iostream>
using namespace std;

/*
Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

Note:

Note that in some languages, such as Java, there is no unsigned integer type. In this case, the input will be given as a signed integer type. It should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 3, the input represents the signed integer. -3.

https://leetcode.com/problems/number-of-1-bits/
O(32), (1)
*/

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
