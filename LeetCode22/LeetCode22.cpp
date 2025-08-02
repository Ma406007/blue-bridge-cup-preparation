#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

// 1.https://leetcode.cn/problems/maximum-number-of-fish-in-a-grid/
class Solution01 {
public:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
            return 0;
        }

        int ans = grid[i][j];
        grid[i][j] = 0;

        ans += dfs(grid, i - 1, j);
        ans += dfs(grid, i + 1, j);
        ans += dfs(grid, i, j - 1);
        ans += dfs(grid, i, j + 1);

        return ans;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int ans = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                ans = max(ans, dfs(grid, i, j));
            }
        }

        return ans;
    }
};

// 2.https://leetcode.cn/problems/coloring-a-border/
class Solution {
public:
    int vis[55][55];// 0:未搜 1:已搜 2:已搜且为边界
    int dx[4] = { 0, -1, 0, 1 }, dy[4] = { 1, 0, -1, 0 };
    int n, m;
    void dfs(vector<vector<int>>& grid, int x, int y) {
        vis[x][y] = 1;// 访问(x,y)
        for (int i = 0; i < 4; i++) {// 从(x,y)扩展(nx,ny)
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                grid[x][y] == grid[nx][ny]) {
                if (!vis[nx][ny])
                    dfs(grid, nx, ny);
            }
            else
                vis[x][y] = 2;// 说明(x,y)与矩阵边界或颜色不同点相邻，因此该点为连通块边界
        }
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        n = grid.size(), m = grid[0].size();
        dfs(grid, row, col);
        for (int i = 0; i < n; i++) {// 将标记为连通块边界的点染色
            for (int j = 0; j < m; j++)
                if (vis[i][j] == 2)
                    grid[i][j] = color;
        }
        return grid;
    }
};