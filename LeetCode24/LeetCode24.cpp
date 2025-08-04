#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// 1.https://leetcode.cn/problems/number-of-closed-islands/
class Solution {
public:
    void dfs(vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 1) {
            return;
        }

        grid[row][col] = 1;

        dfs(grid, row - 1, col);
        dfs(grid, row + 1, col);
        dfs(grid, row, col - 1);
        dfs(grid, row, col + 1);
    }

    int closedIsland(vector<vector<int>>& grid) {
        if (grid.size() < 3 || grid[0].size() < 3) {
            return 0;
        }

        for (int i = 0; i < grid.size(); i++) {
            int step = i == 0 || i == grid.size() - 1 ? 1 : grid[0].size() - 1;
            for (int j = 0; j < grid[0].size(); j += step) {
                dfs(grid, i, j);
            }
        }

        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 0) {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }

        return ans;
    }
};

// 2.https://leetcode.cn/problems/surrounded-regions/
class Solution {
public:
    int m, n;

    void dfs(vector<vector<char>>& board, int x, int y) {
        if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O') {
            return;
        }
        board[x][y] = 'A';
        dfs(board, x + 1, y);
        dfs(board, x - 1, y);
        dfs(board, x, y + 1);
        dfs(board, x, y - 1);
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
        if (m == 0) {
            return;
        }
        n = board[0].size();
        for (int i = 0; i < m; i++) {
            dfs(board, i, 0); // 访问第一列
            dfs(board, i, n - 1); //访问最后一列
        }
        for (int i = 1; i < n - 1; i++) {
            dfs(board, 0, i); // 访问第一行
            dfs(board, m - 1, i); // 访问最后一行
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

// 3.https://leetcode.cn/problems/count-sub-islands/
class Solution {
public:
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int row, int col) {
        if (row < 0 || row >= grid2.size() || col < 0 || col >= grid2[0].size() || grid2[row][col] != 1) {
            return true;
        }

        grid2[row][col] = 2;

        bool ans = true;
        if (grid1[row][col] != 1) {
            ans = false;
        }

        ans = dfs(grid1, grid2, row - 1, col) && ans;
        ans = dfs(grid1, grid2, row + 1, col) && ans;
        ans = dfs(grid1, grid2, row, col - 1) && ans;
        ans = dfs(grid1, grid2, row, col + 1) && ans;

        return ans;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count = 0;

        for (int i = 0; i < grid1.size(); i++) {
            for (int j = 0; j < grid1[0].size(); j++) {
                if (grid2[i][j] == 1) {
                    if (dfs(grid1, grid2, i, j)) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};