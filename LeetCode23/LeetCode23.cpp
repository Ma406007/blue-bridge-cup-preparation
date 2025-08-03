#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

// 1.https://leetcode.cn/problems/number-of-enclaves/
class Solution {
public:
    vector<vector<int>> dirs = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    void dfs(const vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == 0 || visited[row][col]) {
            return;
        }

        visited[row][col] = true;

        for (auto& dir : dirs) {
            dfs(grid, row + dir[0], col + dir[1]);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        this->m = grid.size();
        this->n = grid[0].size();
        this->visited = vector<vector<bool>>(m, vector<bool>(n, false));

        // 访问第一行和最后一行
        for (int i = 0; i < m; i++) {
            dfs(grid, i, 0);
            dfs(grid, i, n - 1);
        }
        // 访问第一列和最后一列
        for (int j = 1; j < n - 1; j++) {
            dfs(grid, 0, j);
            dfs(grid, m - 1, j);
        }

        int enclaves = 0;
        // 访问非矩阵边界的单元格
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                // 如果没有访问过就是飞地
                if (grid[i][j] == 1 && !visited[i][j]) {
                    enclaves++;
                }
            }
        }

        return enclaves;
    }

private:
    int m, n;
    vector<vector<bool>> visited;
};

// 2.https://leetcode.cn/problems/maximum-number-of-moves-in-a-grid/
class Solution {
public:
    int dfs(vector<vector<int>>& grid, int row, int col, int prev) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || visited[row][col] || prev >= grid[row][col]) {
            return -1;
        }

        int top = 0, right = 0, bottom = 0;
        visited[row][col] = true;

        top = 1 + dfs(grid, row - 1, col + 1, grid[row][col]);
        right = 1 + dfs(grid, row, col + 1, grid[row][col]);
        bottom = 1 + dfs(grid, row + 1, col + 1, grid[row][col]);

        return max(top, max(right, bottom));
    }

    int maxMoves(vector<vector<int>>& grid) {
        this->row = grid.size();
        this->col = grid[0].size();
        this->visited = vector<vector<bool>>(row, vector<bool>(col, false));

        int ans = 0;

        for (int i = 0; i < grid.size(); i++) {
            ans = max(ans, dfs(grid, i, 0, 0));
        }

        return ans;
    }

private:
    int row, col;
    vector<vector<bool>> visited;
};