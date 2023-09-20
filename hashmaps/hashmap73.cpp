#include <vector>
#include <string>
#include <unordered_map>
#include <array>
#include <iostream>
#include <sstream>
using namespace std;

// 遍历整个矩阵，碰到0把其中的行列放入vector<int,int> 中
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        vector<pair<int, int>> zeros;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    zeros.push_back({i, j});
                }
            }
        }
        for (const auto &zero : zeros)
        {
            for (int i = 0; i < m; i++)
            {
                matrix[i][zero.second] = 0;
            }
            for (int j = 0; j < n; j++)
            {
                matrix[zero.first][j] = 0;
            }
        }
    }
};

int main() {
    Solution solution;
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    solution.setZeroes(matrix);

    // 打印结果矩阵
    for (const auto &row : matrix) {
        for (const auto &cell : row) {
            cout << cell << ' ';
        }
        cout << '\n';
    }

    return 0;
}