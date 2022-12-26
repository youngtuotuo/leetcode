#include <vector>
#include <string>
#include <iostream>
using namespace std;

/* Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

https://leetcode.com/problems/generate-parentheses/

O(2^n), O(n) */

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(n, 0, 0, "", result);
        return result;
    }
private:
    void generate(int n, int open, int close, string str, vector<string>& result) {
        if (open == n && close == n) {
            result.push_back(str);
            return;
        }

        if (open < n) {
            generate(n, open + 1, close, str + '(', result);
        }
        if (open > close) {
            generate(n, open, close + 1, str + ')', result);
        }
    }
};



int main (int argc, char *argv[])
{
    int n = 3;
    cout << '{' ;
    for (string s: Solution().generateParenthesis(n)) {
        cout << s << ", ";
    }
    cout << '}' << endl;
    return 0;
}
