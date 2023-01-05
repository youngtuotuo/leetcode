#include <iostream>
#include <vector>
using namespace std;

/* You are given an m x n integer matrix matrix with the following two
properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous
row. Given an integer target, return true if target is in matrix or false
otherwise.

You must write a solution in O(log(m * n)) time complexity.

https://leetcode.com/problems/search-a-2d-matrix/

O(log m + log n), O(1)
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int rows(matrix.size() - 1), cols(matrix[0].size() - 1);

        int top(0), bot(rows);
        int row(0);
        while (top <= bot) {
            row = top + (bot - top) / 2;
            if (target > matrix[row][cols]) {
                top = row + 1;
            } else if (target < matrix[row][0]) {
                bot = row - 1;
            } else {
                break;
            }
        }

        if (!(top <= bot)) {
            return false;
        }

        int l(0), r(cols);
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (target > matrix[row][m]) {
                l = m + 1;
            } else if (target < matrix[row][m]) {
                r = m - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    // vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    vector<vector<int>> matrix = {{1},{3}};
    int target = 3;
    cout << Solution().searchMatrix(matrix, target) << endl;
    return 0;
}
