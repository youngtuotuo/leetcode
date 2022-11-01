#include <iostream>
#include <vector>
using namespace std;

/*
Given an integer n, return an array ans of length n + 1 such that for each i (0
<= i <= n), ans[i] is the number of 1's in the binary representation of i.

https://leetcode.com/problems/counting-bits
O(n), O(n)
*/

class Solution {
  public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            ans[i] = ans[i >> 1] + (i & 1);
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    int n = 5;
    cout << '[';
    for (int n : Solution().countBits(n)) {
        cout << n << ", ";
    }
    cout << ']' << endl;
    return 0;
}
