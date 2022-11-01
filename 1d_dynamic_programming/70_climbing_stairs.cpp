#include <iostream>
using namespace std;

/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you
climb to the top?

https://leetcode.com/problems/climbing-stairs/
O(n-1), O(1)
*/

class Solution {
  public:
    int climbStairs(int n) {
        int one = 1, two = 1;
        for (int i = 0; i < n - 1; i++) {
            int temp = one + two;
            two = one;
            one = temp;
        }
        return one;
    }
};

int main(int argc, char *argv[]) {
    int n = 3;
    cout << Solution().climbStairs(n) << endl;
    return 0;
}
