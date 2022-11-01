#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
  Given an array of strings strs, group the anagrams together. You can return
  the answer in any order.

  An Anagram is a word or phrase formed by rearranging the letters of a
  different word or phrase, typically using all the original letters exactly
  once. https://leetcode.com/problems/group-anagrams/ O(m * n), m is the number
  of strings, n is the average length of the strings we get
*/

// encode each str into a key, anagram will give the same key
class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> pair;
        for (string s : strs) {
            string key = getKey(s);
            pair[key].push_back(s);
        }
        vector<vector<string>> res;
        for (auto it = pair.begin(); it != pair.end(); it++) {
            res.push_back(it->second);
        }
        return res;
    }

  private:
    string getKey(string str) {
        vector<int> count(26);
        for (char s : str) {
            count[s - 'a']++;
        }
        string key = "";
        for (int i : count) {
            key.append(to_string(i + 'a'));
        }
        return key;
    }
};

int main(int argc, char *argv[]) {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = Solution().groupAnagrams(strs);
    for (vector<string> e : ans) {
        cout << '[';
        for (string s : e) {
            cout << s << ',';
        }
        cout << "],";
    }
    cout << endl;
    return 0;
}
