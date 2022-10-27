#include <iostream>
#include <vector>
using namespace std;

/*
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

https://leetcode.com/problems/plus-one/
O(n), O(1)
*/

class Solution {
  public:
    vector<int> plusOne(vector<int>& digits) {
      for (int i = digits.size() - 1; i >= 0; i--) {
        if (digits[i] < 9) {
          digits[i]++;
          return digits;
        }
        digits[i] = 0;
      }
      digits[0] = 1;
      digits.push_back(0);
      return digits;
    }
};


int main (int argc, char *argv[])
{
  vector<int> digits = {9};
  for (int d: Solution().plusOne(digits)) {
    cout << d << ' '; 
  }
  cout << endl;
  return 0;
}
