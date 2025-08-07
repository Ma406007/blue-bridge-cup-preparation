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
    // �����a���������������ϵĵ�a��������,����л�
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
        vector<int> area; // �洢ÿ������������index = ���� id - 2���� 2 ��ʼ��ţ�

        auto dfs = [&](this auto&& dfs, int i, int j) -> int {
            grid[i][j] = area.size() + 2; // ��¼ (i,j) �����ĸ���
            int size = 1;
            for (auto& [dx, dy] : dirs) {
                int x = i + dx, y = j + dy;

                if (0 <= x && x < n && 0 <= y && y < n && grid[x][y] == 1) {
                    size += dfs(x, y);
                }
            }
            return size;
            };

        // ------------------------ ��һ�� DFS ------------------------
        // ����ÿһ�����ӣ��ҳ����е��첢��� + ͳ�����
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    area.push_back(dfs(i, j));
                }
            }
        }

        // ------------------------ ����������� ------------------------
        // ���һ�����춼û�У�˵��ȫ�� 0�����ֻ�ܱ�һ�� 0 Ϊ 1��������� 1
        if (area.empty()) {
            return 1;
        }

        int ans = 0; // ��¼���ɵõ��ĵ������
        unordered_set<int> s; // ������¼��ǰ 0 ��Χ�Ĳ�ͬ���� id�������ظ�
        // ------------------------ �ڶ��� ���� 0 ------------------------
        // ö��ÿһ�� 0�����Խ������ 1������������Щ����
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    continue;
                }

                s.clear(); // �����һ�ֵĵ��� id ����

                int new_area = 1; // ��ǰ����Ϊ 1 �󣬳�ʼ����� 1������
                // ���ĸ�������û���ھӵ���
                for (auto& [dx, dy] : dirs) {
                    int x = i + dx, y = j + dy;
                    // Խ���������0 ���������ظ����죨id ���� set �У�Ҳ����
                    if (0 <= x && x < n && 0 <= y && y < n && grid[x][y] && s.insert(grid[x][y]).second) {
                        // �ۼ��������������id ��Ӧ�����Ϊ area.get(id - 2)��
                        new_area += area[grid[x][y] - 2]; // �ۼ����
                    }
                }
                ans = max(ans, new_area);
            }
        }

        // ������ ans ��ȻΪ 0��˵�����и��Ӷ��� 1������ n^2
        return ans ? ans : n * n;
    }
};

// 3.