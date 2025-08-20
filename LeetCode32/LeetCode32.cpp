#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<deque>
#include<queue>
#include<algorithm>
using namespace std;

// 1.https://leetcode.cn/problems/find-a-safe-walk-through-a-grid/
class Solution01 {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        this->row = grid.size(), this->col = grid[0].size();

        // 邻接矩阵
        vector<vector<int>> dis(row, vector<int>(col, INT_MAX));
        dis[0][0] = grid[0][0];

        deque<pair<int, int>> dq;
        dq.emplace_front(0, 0);

        while (!dq.empty()) {
            auto cur = dq.front();
            dq.pop_front();

            for (int i = 0; i < 4; i++) {
                int nx = cur.first + dx[i], ny = cur.second + dy[i];

                if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
                    int cost = grid[nx][ny];

                    // Dijkstra算法的精髓（贪心思想）每次更新总是取最短路径进行更新，局部->全局
                    if (dis[cur.first][cur.second] + cost < dis[nx][ny]) {
                        dis[nx][ny] = dis[cur.first][cur.second] + cost;
                        cost == 0 ? dq.emplace_front(nx, ny) : dq.emplace_back(nx, ny);
                    }
                }
            }
        }

        return dis[row - 1][col - 1] < health;
    }

private:
    int row, col;
    int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
};

// 2.https://leetcode.cn/problems/minimum-obstacle-removal-to-reach-corner/
class Solution02 {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        this->row = grid.size(), this->col = grid[0].size();

        vector<vector<int>> dis(row, vector<int>(col, INT_MAX));
        dis[0][0] = grid[0][0];

        deque<pair<int, int>> dq;
        dq.emplace_front(0, 0);

        while (!dq.empty()) {
            auto cur = dq.front();
            dq.pop_front();

            for (int i = 0; i < 4; i++) {
                int nx = cur.first + dx[i], ny = cur.second + dy[i];

                if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
                    int cost = grid[nx][ny];

                    if (dis[cur.first][cur.second] + cost < dis[nx][ny]) {
                        dis[nx][ny] = dis[cur.first][cur.second] + cost;
                        cost == 0 ? dq.emplace_front(nx, ny) : dq.emplace_back(nx, ny);
                    }
                }
            }
        }

        return dis[row - 1][col - 1];
    }

private:
    int row, col;
    int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
};

// 3.https://leetcode.cn/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/
using PII = pair<int, int>;

class Solution03 {
private:
    static constexpr int dirs[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dist(m * n, INT_MAX);
        vector<int> seen(m * n, 0);
        dist[0] = 0;
        priority_queue<PII, vector<PII>, greater<PII>> q;
        q.emplace(0, 0);

        while (!q.empty()) {
            auto [cur_dis, cur_pos] = q.top();
            q.pop();
            if (seen[cur_pos]) {
                continue;
            }
            seen[cur_pos] = 1;
            int x = cur_pos / n;
            int y = cur_pos % n;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                int new_pos = nx * n + ny;
                int new_dis = cur_dis + (grid[x][y] != i + 1);

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && new_dis < dist[new_pos]) {
                    dist[new_pos] = new_dis;
                    q.emplace(new_dis, new_pos);
                }
            }
        }

        return dist[m * n - 1];
    }
};

// 4.https://leetcode.cn/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/
using PII = pair<int, int>;

class Solution04 {
private:
    static constexpr int dirs[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dist(m * n, INT_MAX);
        vector<int> seen(m * n, 0);
        dist[0] = 0;
        deque<int> q;
        q.push_back(0);

        while (!q.empty()) {
            auto cur_pos = q.front();
            q.pop_front();
            if (seen[cur_pos]) {
                continue;
            }
            seen[cur_pos] = 1;
            int x = cur_pos / n;
            int y = cur_pos % n;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                int new_pos = nx * n + ny;
                int new_dis = dist[cur_pos] + (grid[x][y] != i + 1);

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && new_dis < dist[new_pos]) {
                    dist[new_pos] = new_dis;
                    if (grid[x][y] == i + 1) {
                        q.push_front(new_pos);
                    }
                    else {
                        q.push_back(new_pos);
                    }
                }
            }
        }

        return dist[m * n - 1];
    }
};