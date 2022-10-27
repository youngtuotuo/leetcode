#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
  Given two strings s and t, return true if t is an anagram of s, and false
  otherwise. An Anagram is a word or phrase formed by rearranging the letters of
  a different word or phrase, typically using all the original letters exactly once.

  https://leetcode.com/problems/valid-anagram/
  O(n), O(26)
*/
class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
      return false;
    }

    vector<int> count(26);

    for (int i = 0; i < s.size(); i++) {
      count[s[i] - 'a']++;
    }

    for (int j = 0; j < t.size(); j++) {
      count[t[j] - 'a']--;
      if (count[t[j] - 'a'] < 0) {
        return false;
      }
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  string s = "anagram";
  string t = "nagaram";
  bool ans = Solution().isAnagram(s, t);
  cout << ans << endl;
  return 0;
}
