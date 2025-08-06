#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

// 1.https://leetcode.cn/problems/pacific-atlantic-water-flow/
class Solution {
public:
    void dfs(vector<vector<int>>& heights, vector<vector<int>>& visited, int row, int col) {
        // 访问过了
        if (visited[row][col]) {
            return;
        }
        visited[row][col] = 1;

        if (P[row][col] && A[row][col]) {
            ans.push_back({ row, col });
        }

        if (row - 1 >= 0 && heights[row - 1][col] >= heights[row][col]) {
            dfs(heights, visited, row - 1, col);
        }
        if (row + 1 < n && heights[row + 1][col] >= heights[row][col]) {
            dfs(heights, visited, row + 1, col);
        }

        if (col - 1 >= 0 && heights[row][col - 1] >= heights[row][col]) {
            dfs(heights, visited, row, col - 1);
        }

        if (col + 1 < m && heights[row][col + 1] >= heights[row][col]) {
            dfs(heights, visited, row, col + 1);
        }

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        this->n = heights.size(), this->m = heights[0].size();
        this->P = this->A = vector<vector<int>>(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            dfs(heights, P, i, 0);
            dfs(heights, A, i, m - 1);
        }
        for (int j = 0; j < m; j++) {
            dfs(heights, P, 0, j);
            dfs(heights, A, n - 1, j);
        }

        return ans;
    }

private:
    vector<vector<int>> P, A, ans;
    int n, m;
};

// 2.https://leetcode.cn/problems/minesweeper/
class Solution {
public:
    int dir_x[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };
    int dir_y[8] = { 1, 0, -1, 0, 1, -1, 1, -1 };

    void dfs(vector<vector<char>>& board, int x, int y) {
        int cnt = 0;

        for (int i = 0; i < 8; ++i) {
            int tx = x + dir_x[i];
            int ty = y + dir_y[i];

            if (tx < 0 || tx >= board.size() || ty < 0 || ty >= board[0].size()) {
                continue;
            }

            cnt += board[tx][ty] == 'M';
        }

        if (cnt > 0) {
            // 规则 3
            board[x][y] = cnt + '0';
        }
        else {
            // 规则 2
            board[x][y] = 'B';

            for (int i = 0; i < 8; ++i) {
                int tx = x + dir_x[i];
                int ty = y + dir_y[i];

                if (tx < 0 || tx >= board.size() || ty < 0 || ty >= board[0].size() || board[tx][ty] != 'E') {
                    continue;
                }

                dfs(board, tx, ty);
            }
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[0], y = click[1];

        if (board[x][y] == 'M') {
            // 规则 1
            board[x][y] = 'X';
        }
        else {
            dfs(board, x, y);
        }

        return board;
    }
};

// 3.