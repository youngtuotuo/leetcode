#include <iostream>
#include <cmath>
using namespace std;


/*
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

https://leetcode.com/problems/happy-number/
O(n), O(1)
*/

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
