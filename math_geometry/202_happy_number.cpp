#include <iostream>
#include <cmath>
using namespace std;


// https://leetcode.com/problems/happy-number/
// O(n), O(1)
class Solution {
public:
  bool isHappy(int n) {
    int slow = n;
    int fast = sumSquareBits(n);
    while (slow != fast) {
      slow = sumSquareBits(slow);
      fast = sumSquareBits(fast);
      fast = sumSquareBits(fast);
    }
    return fast == 1;
  }

private:
  int sumSquareBits(int n) {
    int output = 0;
    while (n > 0) {
      output += pow(n % 10, 2);
      n /= 10;
    }
    return output;
  }
};

int main(int argc, char *argv[]) {
  int n = 19;
  cout << Solution().isHappy(n) << endl;
  return 0;
}
