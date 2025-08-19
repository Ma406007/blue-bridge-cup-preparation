#include<iostream>
#include<string>
#include<unordered_map>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

// 1.https://leetcode.cn/problems/number-of-zero-filled-subarrays/?envType=daily-question&envId=2025-08-19
class Solution01 {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int last = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                last = i;
            }
            else {
                ans += i - last;
            }
        }
        return ans;
    }
};

// 2.https://leetcode.cn/problems/shortest-bridge/
class Solution02 {
public:
    void dfs(int x, int y, vector<vector<int>>& grid, queue<pair<int, int>>& qu) {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] != 1) {
            return;
        }

        qu.emplace(x, y);
        // dfs时，我们可以将已经遍历过的位置标记为−1
        grid[x][y] = -1;

        dfs(x - 1, y, grid, qu);
        dfs(x + 1, y, grid, qu);
        dfs(x, y - 1, grid, qu);
        dfs(x, y + 1, grid, qu);
    }

    int shortestBridge(vector<vector<int>>& grid) {
        this->row = grid.size(), this->col = grid[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    queue<pair<int, int>> q;
                    // 利用dfs求出其中的一座岛
                    dfs(i, j, grid, q);

                    // 随后我们从这座岛中的所有位置开始进行bfs，当它们到达了任意的1时，即表示搜索到了第二个岛，搜索的层数就是答案
                    int step = 0;
                    while (!q.empty()) {
                        int size = q.size();
                        for (int k = 0; k < size; k++) {
                            auto cur = q.front();
                            q.pop();

                            for (int m = 0; m < 4; m++) {
                                int nx = cur.first + dx[m], ny = cur.second + dy[m];
                                if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
                                    if (grid[nx][ny] == 0) {
                                        q.emplace(nx, ny);
                                        grid[nx][ny] = -1;
                                    }
                                    else if (grid[nx][ny] == 1) {
                                        return step;
                                    }
                                }
                            }
                        }

                        step++;
                    }
                }
            }
        }

        return 0;
    }

private:
    int row, col;
    int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
};

// 3.https://leetcode.cn/problems/k-highest-ranked-items-within-a-price-range/
class Solution03 {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        vector<tuple<int, int, int, int>> items; // 距离，价格，行坐标，纵坐标
        queue<tuple<int, int, int>> q;

        q.emplace(start[0], start[1], 0);
        if (pricing[0] <= grid[start[0]][start[1]] && grid[start[0]][start[1]] <= pricing[1]) {
            items.emplace_back(0, grid[start[0]][start[1]], start[0], start[1]);
        }
        grid[start[0]][start[1]] = 0;   // 避免重复遍历

        this->row = grid.size();
        this->col = grid[0].size();

        while (!q.empty()) {
            auto [x, y, d] = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                // 遍历相邻坐标，并进行对应操作
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < row && ny >= 0 && ny < col && grid[nx][ny] > 0) {
                    if (pricing[0] <= grid[nx][ny] && grid[nx][ny] <= pricing[1]) {
                        items.emplace_back(d + 1, grid[nx][ny], nx, ny);
                    }
                    q.emplace(nx, ny, d + 1);
                    grid[nx][ny] = 0;   // 避免重复遍历
                }
            }
        }

        sort(items.begin(), items.end());   // 按照优先级从高到低排序

        vector<vector<int>> res;   // 排名最高 k 件物品的坐标
        int cnt = min(k, static_cast<int>(items.size()));
        for (int i = 0; i < cnt; ++i) {
            auto [d, price, x, y] = items[i];
            res.push_back({ x, y });
        }
        return res;
    }

private:
    int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
    int row, col;
    vector<vector<int>> ans;
};

// 4.https://leetcode.cn/problems/snakes-and-ladders/
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(); // 获取方阵的边长
        int target = n * n;   // 获取方阵尺寸，也是最后要到达目的地

        queue<pair<int, int>> queue_; // 队列用于BFS，存放待搜索的方格编号和到达该方格时的最少移动数
        queue_.emplace(1, 0); // 初始{1,0}入队，表示起点1，0次移动

        vector<vector<bool>> visited(n, vector<bool>(n)); // 用于BFS过程中标记方格是否搜索过

        while (!queue_.empty()) {
            auto node = queue_.front();
            queue_.pop();

            int curr = node.first, cnt = node.second; // 获取当前搜索的方格宾浩和到达该方格的最少移动数
            cnt++;               // 移动数加1

            for (int i = curr + 1; i <= min(target, curr + 6); i++) {
                // 枚举所有下一个可搜索且未搜索过的方格编号
                int r = n - 1 - (i - 1) / n, c = (i - 1) % n; // 根据方格编号获取这个编号的行和列
                c += (n - 1 - 2 * c) * ((n - 1 - r) & 1); // 根据行数修正列数

                if (visited[r][c]) {
                    continue;         // 跳过搜索过的编号
                }
                visited[r][c] = true; // 标记该编号已搜索

                int next = board[r][c] == -1 ? i : board[r][c]; // 如果这个编号所在的方格可以转移到其他格子，转移到对应编号；否则就是在当前编号
                if (next == target) {
                    return cnt;            // 到达终点，直接返回最小移动数
                }

                queue_.emplace(next, cnt); // 加入队列
            }
        }

        return -1; // 退出循环说明没有到达目的地
    }
};

// 5.https://leetcode.cn/problems/cut-off-trees-for-golf-event/
class Solution05 {
public:
    // 起点：(sx, sy) 终点：(tx, ty)
    int bfs(vector<vector<int>>& forest, int sx, int sy, int tx, int ty) {
        if (sx == tx && sy == ty) {
            return 0;
        }

        int row = forest.size(), col = forest[0].size();

        int step = 0;

        queue<pair<int, int>> q;
        q.emplace(sx, sy);

        vector<vector<int>> visited(row, vector<int>(col, 0));
        visited[sx][sy] = 1;

        while (!q.empty()) {
            step++;

            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto cur = q.front();
                q.pop();

                for (int j = 0; j < 4; j++) {
                    int nx = cur.first + dx[j], ny = cur.second + dy[j];
                    if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
                        // 1是平地，不砍，但扔要计算步数和标记访问
                        if (!visited[nx][ny] && forest[nx][ny] > 0) {
                            if (nx == tx && ny == ty) {
                                return step;
                            }

                            visited[nx][ny] = 1;
                            q.emplace(nx, ny);
                        }
                    }
                }
            }
        }

        return -1;
    }

    int cutOffTree(vector<vector<int>>& forest) {
        vector<pair<int, int>> trees;
        int row = forest.size(), col = forest[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (forest[i][j] > 1) {
                    trees.emplace_back(i, j);
                }
            }
        }

        sort(trees.begin(), trees.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
            return forest[a.first][a.second] < forest[b.first][b.second];
            });

        int cx = 0, cy = 0;
        int ans = 0;
        for (int i = 0; i < trees.size(); i++) {
            int steps = bfs(forest, cx, cy, trees[i].first, trees[i].second);

            // 只要有一次遍历得到steps等于-1，就说明无法砍掉所有的树
            if (steps == -1) {
                return -1;
            }

            ans += steps;
            cx = trees[i].first, cy = trees[i].second;
        }

        return ans;
    }

private:
    int dx[4] = { -1 , 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
};