#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

// https://leetcode.com/problems/valid-sudoku/
// O(s^2), O(s^2), s is the size of the sudoku board

class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    const int CNT = 9;
    bool row[CNT][CNT] = {{false}};
    bool col[CNT][CNT] = {{false}};
    bool sub[CNT][CNT] = {{false}};

    for (int r = 0; r < CNT; r++) {
      for (int c = 0; c < CNT; c++) {
        if (board[r][c] == '.') {
          continue;
        }

        int idx = board[r][c] - '0' - 1;
        int area = (r / 3) * 3 + (c / 3);
        if (row[r][idx] || col[c][idx] || sub[area][idx]) {
          return false;
        }

        row[r][idx] = true;
        col[c][idx] = true;
        sub[area][idx] = true;
      }
    }
    return true;
  }
  bool another(vector<vector<char>> &board) {
    unordered_map<int, set<char>> cols;
    unordered_map<int, set<char>> rows;
    unordered_map<int, set<char>> squares;

    for (int r = 0; r < 9; r++) {
      for (int c = 0; c < 9; c++) {
        if (board[r][c] == '.') {
          continue;
        }
        if (rows[r].find(board[r][c]) != rows[r].end() ||
            cols[c].find(board[r][c]) != cols[c].end() ||
            squares[(r / 3) * 3 + (c / 3)].find(board[r][c]) !=
                squares[(r / 3) * 3 + (c / 3)].end()) {
          return false;
        }
        rows[r].insert(board[r][c]);
        cols[c].insert(board[r][c]);
        squares[(r / 3) * 3 + (c / 3)].insert(board[r][c]);
      }
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  for (vector<char> v : board) {
    for (char c : v) {
      cout << c << " ";
    }
    cout << endl;
  }
  cout << endl;
  cout << Solution().another(board) << endl;
  return 0;
}
