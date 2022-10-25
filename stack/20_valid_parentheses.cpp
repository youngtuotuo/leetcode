#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

// https://leetcode.com/problems/valid-parentheses/
// O(n), O(n)
class Solution {
public:
  bool isValid(string s) {
    stack<char> left;
    unordered_map<char, char> pair;
    pair = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
    for (char c : s) {
      if (pair.find(c) != pair.end()) {
        left.push(c);
      } else {
        if (left.size() == 0) {
          return false;
        } else {
          char last = left.top();
          left.pop();
          if (pair[last] != c) {
            return false;
          }
        }
      }
    }
    return (left.size() == 0);
  }
};

int main(int argc, char *argv[]) {

  string s = "()";

  bool ans = Solution().isValid(s);
  cout << ans << endl;
  return 0;
}
