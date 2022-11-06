#include <bits/stdc++.h>
#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/* Given two strings s and t of lengths m and n respectively, return the minimum
window substring of s such that every character in t (including duplicates) is
included in the window. If there is no such substring, return the empty string
"".

The testcases will be generated such that the answer is unique.
https://leetcode.com/problems/minimum-window-substring/

O(m + n), O(m + n) */

class Solution {
  public:
    string minWindow(string &s, string &t) {
        if (t == "")
            return "";
        unordered_map<char, int> countT, window;
        for (char c : t) {
            countT[c]++;
        }

        int have = 0, need = t.size();
        int res[2] = {-1, -1}, resLength = INT_MAX;
        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            char c = s[r];
            window[c]++;
            if (countT.find(c) != countT.end() && countT[c] == window[c]) {
                have += 1;
            }
            while (have == need) {
                if ((r - l + 1) < resLength) {
                    res[0] = l;
                    res[1] = r;
                    resLength = r - l + 1;
                }
                window[s[l]] -= 1;
                if (countT.find(s[l]) != countT.end() &&
                    window[s[l]] < countT[s[l]]) {
                    have -= 1;
                }
                l++;
            }
        }
        if (resLength != INT_MAX) {
            return s.substr(res[0], resLength);
        }
        return "";
    }
};

int main(int argc, char *argv[]) {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << Solution().minWindow(s, t) << endl;
    return 0;
}
