#include <iostream>
#include <string>
#include <vector>
using namespace std;
/* Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

https://leetcode.com/problems/permutation-in-string/
O(n), O(26) */

class Solution {
    public:
        bool checkInclusion(string& s1, string& s2) {
            int s1Size = s1.size();
            int s2Size = s2.size();
            if (s1Size > s2Size) {
                return false;
            }

            vector<int> count(26);
            for (int i = 0; i < s1Size; i++) {
                count[s1[i] - 'a']++;
                count[s2[i] - 'a']--;
            }
            if (isPermutation(count)) {
                return true;
            }

            for (int i = s1Size; i < s2Size; i++) {
                count[s2[i] - 'a']--;
                count[s2[i - s1Size] - 'a']++;
                if (isPermutation(count)) {
                    return true;
                }
            }
            return false;
            
        }

    private:
            bool isPermutation(vector<int> count) {
                for (int c: count) {
                    if (c != 0) {
                        return false;
                    }
                }
                return true;
            }
};

int main (int argc, char *argv[])
{
    string s1 = "ab";
    string s2 = "eidbaooo";
    cout << Solution().checkInclusion(s1, s2) << endl;
    return 0;
}
