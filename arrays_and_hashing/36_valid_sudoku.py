from typing import List
import collections

# https://leetcode.com/problems/valid-sudoku/
# O(s^2), O(s^2), s is the size of the sudoku board
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        cols = collections.defaultdict(set)
        rows = collections.defaultdict(set)
        squares = collections.defaultdict(set)

        for r in range(9):
            for c in range(9):
                if board[r][c] == ".":
                    continue
                if (
                    board[r][c] in rows[r]
                    or board[r][c] in cols[c]
                    or board[r][c] in squares[(r // 3, c // 3)]
                ):
                    return False
                cols[c].add(board[r][c])
                rows[r].add(board[r][c])
                squares[(r // 3, c // 3)].add(board[r][c])
        return True

    def another(self, board: List[List[str]]) -> bool:
        CONST = 9
        cols = [[False] * CONST for _ in range(CONST)]
        rows = [[False] * CONST for _ in range(CONST)]
        squares = [[False] * CONST for _ in range(CONST)]
        for r in range(CONST):
            for c in range(CONST):
                if board[r][c] == ".":
                    continue
                if (
                    cols[c][ord(board[r][c]) - ord('0') - 1]
                    or rows[r][ord(board[r][c]) - ord('0') - 1]
                    or squares[(r // 3) * 3 + (c // 3)][ord(board[r][c]) - ord('0') - 1]
                ):
                    return False
                cols[c][ord(board[r][c]) - ord('0') - 1] = True
                rows[r][ord(board[r][c]) - ord('0') - 1] = True
                squares[(r // 3) * 3 + (c // 3)][ord(board[r][c]) - ord('0') - 1] = True

        return True


if __name__ == "__main__":
    board = [
        ["5", "3", ".", ".", "7", ".", ".", ".", "."],
        ["6", ".", ".", "1", "9", "5", ".", ".", "."],
        [".", "9", "8", ".", ".", ".", ".", "6", "."],
        ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
        ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
        ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
        [".", "6", ".", ".", ".", ".", "2", "8", "."],
        [".", ".", ".", "4", "1", "9", ".", ".", "5"],
        [".", ".", ".", ".", "8", ".", ".", "7", "9"],
    ]
    print(Solution().another(board))
