#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/plus-one/
// O(n), O(1)
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
