#include <iostream>
#include <string>
using namespace std;

/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
https://leetcode.com/problems/valid-palindrome/
O(n), O(n)
*/
class Solution {
public:
  bool isPalindrome(string s) {
    int l = 0;
    int r = s.size() - 1;
    while (l < r) {
      while (!isalnum(s[l]) && l < r) {
        l++;
      }
      while (!isalnum(s[r]) && l < r) {
        r--;
      }
      if (tolower(s[l]) != tolower(s[r])) {
        return false;
      }
      l++;
      r--;
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  string s = "raceacar";
  bool ans = Solution().isPalindrome(s);
  cout << ans << endl;
  return 0;
}
