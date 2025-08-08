#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#include<tuple>
using namespace std;

// 1.https://leetcode.cn/problems/nearest-exit-from-entrance-in-maze/
class Solution01 {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int row = maze.size(), col = maze[0].size();

        queue<tuple<int, int, int>> q;
        q.emplace(entrance[0], entrance[1], 0);
        maze[entrance[0]][entrance[1]] = '+';

        while (!q.empty()) {
            auto [cx, cy, d] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = cx + dx[i], ny = cy + dy[i];

                if (nx >= 0 && nx < row && ny >= 0 && ny < col && maze[nx][ny] == '.') {
                    if (nx == 0 || ny == 0 || nx == row - 1 || ny == col - 1) {
                        return d + 1;
                    }

                    maze[nx][ny] = '+';
                    q.emplace(nx, ny, d + 1);
                }
            }
        }

        return -1;
    }

private:
    int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
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

        for (int ans = 1; !q.empty(); ++ans) {
            for (int k = q.size(); k; --k) {
                auto [i, j] = q.front();
                q.pop();

                if (i == n - 1 && j == n - 1) {
                    return ans;
                }

                for (int x = i - 1; x <= i + 1; ++x) {
                    for (int y = j - 1; y <= j + 1; ++y) {
                        if (x >= 0 && x < n && y >= 0 && y < n && !grid[x][y]) {
                            grid[x][y] = 1;
                            q.emplace(x, y);
                        }
                    }
                }
            }
        }

        return -1;
    }
};

// 3.https://leetcode.cn/problems/as-far-from-land-as-possible/
// 超时写法
class Solution03 {
public:
    int bfs(int x, int y) {
        memset(visited, false, sizeof(visited));

        queue<tuple<int, int, int>> q;
        q.emplace(x, y, 0);
        visited[x][y] = true;

        while (!q.empty()) {
            auto [cx, cy, step] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = cx + dx[i], ny = cy + dy[i];

                if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
                    if (!visited[nx][ny]) {
                        visited[nx][ny] = true;
                        q.emplace(nx, ny, step + 1);

                        if (a[nx][ny]) {
                            return step + 1;
                        }
                    }
                }
            }
        }

        return -1;
    }

    int maxDistance(vector<vector<int>>& grid) {
        this->row = grid.size(), this->col = grid.size();
        this->a = grid;

        int ans = -1;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!a[i][j])
                    ans = max(ans, bfs(i, j));
            }
        }

        return ans;
    }

private:
    int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
    int row, col;
    vector<vector<int>> a;

    static constexpr int MAX_N = 100 + 5;
    bool visited[MAX_N][MAX_N];
};

// 多源点
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
            while (size--) {
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