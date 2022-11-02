#include <string>
#include <iostream>
#include <unordered_set>
using namespace std;


/* Given a string s, find the length of the longest substring without repeating characters.
https://leetcode.com/problems/longest-substring-without-repeating-characters/
O(n), O(n) */

class Solution {
public:
    int lengthOfLongestSubstring(string& s) {
        int res = 0, l = 0;
        unordered_set<char> sSet;
        for (int r = 0; r < s.size(); r++) {
            while (sSet.find(s[r]) != sSet.end()) {
                sSet.erase(s[l]);
                l++;
            }
            sSet.insert(s[r]);
            res = max(res, r - l + 1);
        }
        return res;
    }
};



int main (int argc, char *argv[])
{
    string s = "pwwkew";
    cout << Solution().lengthOfLongestSubstring(s) << endl;
    return 0;
}
