#include <iostream>
#include <string>
using namespace std;

// https://leetcode.com/problems/valid-palindrome/
// O(n), O(n)
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
