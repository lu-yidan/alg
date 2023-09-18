#include <iostream>
#include <string>
#include <cstring>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> 
        rows = vector<int>(9, 0),
        cols = vector<int>(9, 0);
        // int rows[9] = {0};
        // int cols[9] = {0};
        int subboxes[3][3] = {0};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int x = 1 << (board[i][j] - '1');
                    if (rows[i] & x || cols[j] & x || subboxes[i / 3][j / 3] & x)
                        return false;
                    rows[i] |= x; 
                    cols[j] |= x; 
                    subboxes[i / 3][j / 3] |= x;
                }
            }
        }
        return true;
    }
};

int main() {
    // Initialize the test cases
 vector<vector<char>> board1 = 
    {{'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}};

vector<vector<char>> board2 = 
    {{'8','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}};

    // Initialize the Solution object
    Solution solution;

    // Print the results of the test cases
    cout << "IsValidSudoku test result for board1: " << boolalpha << solution.isValidSudoku(board1) << endl;
    cout << "IsValidSudoku test result for board2: " << boolalpha << solution.isValidSudoku(board2) << endl;

    return 0;
}