#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
using namespace std;

// 1.
class Solution01 {
public:
    // 如果点a四周有两个及以上的点a被遍历过,则必有环
    bool dfs(int x, int y, vector<vector<char>>& grid) {
        int num = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
                continue;
            }

            if (vis[nx][ny] == grid[x][y]) {
                num++;
                continue;
            }

            if (grid[nx][ny] == grid[x][y]) {
                vis[nx][ny] = grid[x][y];

                if (dfs(nx, ny, grid)) {
                    return true;
                }
            }
        }

        if (num >= 2) {
            return true;
        }
        else {
            return false;
        }
    }

    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j]) {
                    vis[i][j] = grid[i][j];

                    if (dfs(i, j, grid)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

private:
    int vis[500][500];
    int dir[4][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };
    int m, n;
};

// 2.https://leetcode.cn/problems/making-a-large-island/
class Solution {
    static constexpr int dirs[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> area; // 存储每个岛屿的面积，index = 岛屿 id - 2（从 2 开始编号）

        auto dfs = [&](this auto&& dfs, int i, int j) -> int {
            grid[i][j] = area.size() + 2; // 记录 (i,j) 属于哪个岛
            int size = 1;
            for (auto& [dx, dy] : dirs) {
                int x = i + dx, y = j + dy;

                if (0 <= x && x < n && 0 <= y && y < n && grid[x][y] == 1) {
                    size += dfs(x, y);
                }
            }
            return size;
            };

        // ------------------------ 第一轮 DFS ------------------------
        // 遍历每一个格子，找出所有岛屿并编号 + 统计面积
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    area.push_back(dfs(i, j));
                }
            }
        }

        // ------------------------ 特殊情况处理 ------------------------
        // 如果一个岛屿都没有，说明全是 0，最多只能变一个 0 为 1，返回面积 1
        if (area.empty()) {
            return 1;
        }

        int ans = 0; // 记录最大可得到的岛屿面积
        unordered_set<int> s; // 用来记录当前 0 周围的不同岛屿 id，避免重复
        // ------------------------ 第二轮 遍历 0 ------------------------
        // 枚举每一个 0，尝试将它变成 1，看能连接哪些岛屿
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    continue;
                }

                s.clear(); // 清空上一轮的岛屿 id 集合

                int new_area = 1; // 当前这格变为 1 后，初始面积是 1（自身）
                // 看四个方向有没有邻居岛屿
                for (auto& [dx, dy] : dirs) {
                    int x = i + dx, y = j + dy;
                    // 越界就跳过，0 就跳过，重复岛屿（id 已在 set 中）也跳过
                    if (0 <= x && x < n && 0 <= y && y < n && grid[x][y] && s.insert(grid[x][y]).second) {
                        // 累加这个岛屿的面积（id 对应的面积为 area.get(id - 2)）
                        new_area += area[grid[x][y] - 2]; // 累加面积
                    }
                }
                ans = max(ans, new_area);
            }
        }

        // 如果最后 ans 仍然为 0，说明所有格子都是 1，返回 n^2
        return ans ? ans : n * n;
    }
};

// 3.