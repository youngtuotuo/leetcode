#include <iostream>
#include <vector>
#include <string>
using namespace std;

// https://leetcode.com/problems/valid-anagram/
// O(n), O(26)
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
        return true ;
    }
};

int main (int argc, char *argv[])
{
  string s = "anagram";
  string t = "nagaram";
  bool ans = Solution().isAnagram(s, t);
  cout << ans << endl;
  return 0;
}
