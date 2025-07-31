#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;

// 1.https://leetcode.cn/problems/neighboring-bitwise-xor/?envType=daily-question&envId=2025-07-31
class Solution01 {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int s = 0;
        for (int x : derived) {
            s ^= x;
        }
        return s == 0;
    }
};

// 2.https://leetcode.cn/problems/number-of-islands/
class Solution02 {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1') {
            return;
        }

        grid[i][j] = '2';

        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }

        return ans;
    }
};

// 3.https://leetcode.cn/problems/max-area-of-island/
class Solution03 {
public:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1) {
            return 0;
        }

        grid[i][j] = 0;

        int ans = 1;
        ans += dfs(grid, i - 1, j);
        ans += dfs(grid, i + 1, j);
        ans += dfs(grid, i, j - 1);
        ans += dfs(grid, i, j + 1);

        return ans;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0) {
            return 0;
        }

        int ans = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                ans = max(dfs(grid, i, j), ans);
            }
        }

        return ans;
    }
};

// 4.https://leetcode.cn/problems/pond-sizes-lcci/
class Solution04 {
public:
    int dx[8] = { -1, 1, 0, 0, -1, 1, -1, 1 };
    int dy[8] = { 0, 0, -1, 1, -1, -1, 1, 1 };

    int dfs(vector<vector<int>>& land, int i, int j) {
        if (i < 0 || i >= land.size() || j < 0 || j >= land[0].size() || land[i][j] != 0) {
            return 0;
        }

        land[i][j] = 1;

        int ans = 1;
        for (int next = 0; next < 8; next++) {
            ans += dfs(land, i + dx[next], j + dy[next]);
        }

        return ans;
    }

    vector<int> pondSizes(vector<vector<int>>& land) {
        vector<int> ans;

        for (int i = 0; i < land.size(); i++) {
            for (int j = 0; j < land[0].size(); j++) {
                if (land[i][j] == 0) {
                    ans.emplace_back(dfs(land, i, j));
                }
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};

// 5.https://leetcode.cn/problems/YesdPw/
class Solution05 {
public:
    void dfs(vector<string>& grid, int x, int y, int& flag, char ch,
        int& count) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[x].size() ||
            grid[x][y] == '0') {
            flag = 0;
            return;
        }
        if (grid[x][y] != ch) {
            return;
        }

        grid[x][y] = '6';
        count++;
        dfs(grid, x + 1, y, flag, ch, count);
        dfs(grid, x - 1, y, flag, ch, count);
        dfs(grid, x, y + 1, flag, ch, count);
        dfs(grid, x, y - 1, flag, ch, count);
    }

    int largestArea(vector<string>& grid) {
        int n = grid.size(), res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                int flag = 1, count = 0;
                if (grid[i][j] >= '1' && grid[i][j] <= '5') {
                    dfs(grid, i, j, flag, grid[i][j], count);
                    if (flag)
                        res = max(count, res);
                }
            }
        }
        return res;
    }
};

// 6.https://leetcode.cn/problems/island-perimeter/
class Solution06 {
    constexpr static int dx[4] = { 0, 1, 0, -1 };
    constexpr static int dy[4] = { 1, 0, -1, 0 };
public:
    int dfs(int x, int y, vector<vector<int>>& grid, int n, int m) {
        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0) {
            return 1;
        }
        if (grid[x][y] == 2) {
            return 0;
        }
        grid[x][y] = 2;
        int res = 0;
        for (int i = 0; i < 4; ++i) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            res += dfs(tx, ty, grid, n, m);
        }
        return res;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    ans += dfs(i, j, grid, n, m);
                }
            }
        }
        return ans;
    }
};