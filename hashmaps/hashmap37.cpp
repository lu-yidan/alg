#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

private:
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c; // 尝试填充数字c到当前空格

                            if (solve(board))
                                return true; // 填充该数字后，如果找到一个有效解，返回true
                            else
                                board[i][j] = '.'; // 否则撤销当前填充，尝试下一个数字
                        }
                    }

                    return false; // 如果所有数字都无法填充到当前空格，返回false
                }
            }
        }

        return true; // 所有空格都已填充，返回true
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == c) return false; // Check column
            if (board[row][i] == c) return false; // Check row
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false; // Check 3*3 block
        }
        return true;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<vector<char>>board1 = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}};

    sol.solveSudoku(board1);
    for(const auto& row : board1) {
        for (const auto& cell : row) {
            cout << cell << " ";
        }
        cout << "\n";
    }

    return 0;
}