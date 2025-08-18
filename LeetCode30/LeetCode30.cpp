#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<queue>
using namespace std;

// 1.https://leetcode.cn/problems/nearest-exit-from-entrance-in-maze/
class Solution01 {
public:
    int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    int nearestExit(vector<vector<char>>& maze, vector<int>& en) {
        int n = maze.size();
        int m = maze[0].size();

        queue<pair<int, int>> q;
        pair<int, int> begin = { en[0], en[1] };
        q.push({ en[0], en[1] });
        int cnt = 0;

        while (q.size()) {
            int level = q.size();
            for (int i = 0; i < level; ++i) {
                auto cur = q.front();
                q.pop();

                // 越界访问就代表找到出口了
                if ((cur.first == 0 || cur.first == n - 1 || cur.second == m - 1 || cur.second == 0) && (cur != begin)) {
                    return cnt;
                }

                for (int i = 0; i < 4; ++i) {
                    int nx = cur.first + dir[i][0];
                    int ny = cur.second + dir[i][1];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] == '.') {
                        maze[nx][ny] = '+';
                        q.push({ nx, ny });
                    }
                }
            }

            ++cnt;
        }

        return -1;
    }
};

// 2.https://leetcode.cn/problems/shortest-path-in-binary-matrix/
class Solution02 {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0]) {
            return -1;
        }

        int n = grid.size();
        grid[0][0] = 1;
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        int ans = 1;

        while (q.size()) {
            for (int k = q.size(); k; --k) {
                auto [i, j] = q.front();
                q.pop();

                // 到达(n - 1, n - 1)就停下
                if (i == n - 1 && j == n - 1) {
                    return ans;
                }

                // 向八个方向遍历
                for (int x = i - 1; x <= i + 1; ++x) {
                    for (int y = j - 1; y <= j + 1; ++y) {
                        if (x >= 0 && x < n && y >= 0 && y < n && !grid[x][y]) {
                            grid[x][y] = 1;
                            q.emplace(x, y);
                        }
                    }
                }
            }

            ans++;
        }

        return -1;
    }
};

// 3.https://leetcode.cn/problems/as-far-from-land-as-possible/
class Solution03 {
public:
    int maxDistance(vector<vector<int>>& grid) {
        this->row = grid.size(), this->col = grid.size();

        queue<pair<int, int>> q;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j]) {
                    // 将所有陆地放入队列中
                    q.emplace(i, j);
                }
            }
        }

        // 如果队列为空或者队列大小是矩阵grid大小，根据题意没有最大曼哈顿距离，返回-1
        if (q.empty() || q.size() == row * col) {
            return -1;
        }

        // 由于BFS的第一层遍历是从陆地开始的，因此遍历完第一层之后distance应该是0
        int distance = -1;
        // BFS模板
        // 对队列的元素进行遍历
        while (!q.empty()) {
            // 新遍历了一层
            distance++;
            // 遍历该层所有元素
            int size = q.size();
            for (int k = 0; k < size; k++) {
                // BFS永远先遍历队头元素
                auto cur = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nx = cur.first + dx[i], ny = cur.second + dy[i];
                    // 需要判断nx和ny还在矩阵内部
                    if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
                        // 如果是海洋
                        if (!grid[nx][ny]) {
                            // 标记已经遍历过
                            grid[nx][ny] = 2;
                            // 并将其放入队尾
                            q.emplace(nx, ny);
                        }
                    }
                }
            }
        }

        // 最终走了多少层才把海洋遍历完
        return distance;
    }

private:
    int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
    int row, col;
};

// 4.https://leetcode.cn/problems/01-matrix/
class Solution04 {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        this->row = mat.size(), this->col = mat[0].size();
        this->ans = vector<vector<int>>(row, vector<int>(col, 0)), this->visited = vector<vector<int>>(row, vector<int>(col, 0));

        queue<pair<int, int>> q;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (mat[i][j] == 0) {
                    q.emplace(i, j);
                    visited[i][j] = 1;
                }
            }
        }

        int step = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                auto cur = q.front();
                q.pop();

                if (mat[cur.first][cur.second]) {
                    ans[cur.first][cur.second] = step;
                }

                for (int k = 0; k < 4; k++) {
                    int nx = cur.first + dx[k], ny = cur.second + dy[k];
                    if (nx < 0 || nx >= row || ny < 0 || ny >= col || visited[nx][ny]) {
                        continue;
                    }

                    q.emplace(nx, ny);
                    visited[nx][ny] = 1;
                }
            }

            step++;
        }

        return ans;
    }

private:
    int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
    int row, col;
    vector<vector<int>> ans, visited;
};

// 5.https://leetcode.cn/problems/rotting-oranges/
class Solution05 {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        this->row = grid.size(), this->col = grid[0].size();

        int fresh = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 2) {
                    q.emplace(i, j);
                }
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int minute = 0;
        while (!q.empty()) {
            int size = q.size();
            bool rotten = false;

            for (int k = 0; k < size; k++) {
                auto cur = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nx = cur.first + dx[i], ny = cur.second + dy[i];

                    if (nx < 0 || nx >= row || ny < 0 || ny >= col || !grid[nx][ny]) {
                        continue;
                    }
                    if (grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        // 能够腐烂新鲜橘子就把rotten设为true
                        rotten = true;
                        // 腐烂一个新鲜橘子，新鲜橘子的数量就减一
                        fresh--;
                        q.emplace(nx, ny);
                    }
                }
            }

            if (rotten) {
                minute++;
            }
        }

        // 如果最后还有新鲜橘子则说明无法将所有新鲜橘子全部腐烂
        return fresh ? -1 : minute;
    }

private:
    int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
    int row, col;
};

// 6.https://leetcode.cn/problems/map-of-highest-peak/
class Solution06 {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        this->row = isWater.size(), this->col = isWater[0].size();
        this->ans = vector<vector<int>>(row, vector<int>(col, 0)), this->visited = vector<vector<int>>(row, vector<int>(col, 0));

        queue<pair<int, int>> q;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (isWater[i][j]) {
                    q.emplace(i, j);
                    visited[i][j] = 1;
                }
            }
        }

        int step = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                auto cur = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nx = cur.first + dx[i], ny = cur.second + dy[i];
                    if (nx < 0 || nx >= row || ny < 0 || ny >= col || visited[nx][ny]) {
                        continue;
                    }

                    ans[nx][ny] = step;
                    visited[nx][ny] = 1;
                    q.emplace(nx, ny);
                }
            }

            step++;
        }

        return ans;
    }

private:
    int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
    int row, col;
    vector<vector<int>> ans;
    vector<vector<int>> visited;
};

// 7.https://leetcode.cn/problems/shortest-bridge/
class Solution07 {
public:
    void dfs(int x, int y, vector<vector<int>>& grid, queue<pair<int, int>>& qu) {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] != 1) {
            return;
        }

        qu.emplace(x, y);
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
                    dfs(i, j, grid, q);

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

// 8.https://leetcode.cn/problems/k-highest-ranked-items-within-a-price-range/
class Solution08 {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        vector<tuple<int, int, int, int>> items;
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