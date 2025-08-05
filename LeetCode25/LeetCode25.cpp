#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

// 1.https://leetcode.cn/problems/fruits-into-baskets-ii/?envType=daily-question&envId=2025-08-05
class Solution01 {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int count = 0;
        int n = baskets.size();
        for (auto fruit : fruits) {
            int unset = 1;
            for (int i = 0; i < n; i++) {
                if (fruit <= baskets[i]) {
                    baskets[i] = 0;
                    unset = 0;
                    break;
                }
            }
            count += unset;
        }
        return count;
    }
};

// 2.https://leetcode.cn/problems/check-if-there-is-a-valid-path-in-a-grid/
class Solution {
public:
    bool dfs(int x, int y, int dir, vector<vector<int>>& grid) {
        vis[x][y] = 1;
        if (x == m - 1 && y == n - 1) {
            return true;
        }
        int xx = x + dx[dir];
        int yy = y + dy[dir];
        if (xx < 0 || yy < 0 || xx >= m || yy >= n) {
            return false;
        }
        int nxt = grid[xx][yy]; // 得到下一块拼图的编号
        if (pipe[nxt][dir] != -1 && !vis[xx][yy]) {
            return dfs(xx, yy, pipe[nxt][dir], grid); // 如果当前方向可走，则方向改变，继续走。
        }
        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(vis, 0, sizeof(vis));
        int sta = grid[0][0];
        for (int i = 0; i < 4; ++i) {
            // 当前方向可以走
            if (pipe[sta][i] != -1) {
                if (dfs(0, 0, pipe[sta][i], grid)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    int m, n, dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 }; // 0下、1右、2上、3左
    // 第一个下标是街道类型
    // 第二个下标是街道的走向，按逆时针：上，左，下，右。表示从哪个方向进入街道后从哪个方向出去
    // 第二个下标对应的取值：0代表向下，1代表向右，2代表向上，3代表向左，-1代表不可走
    int pipe[7][4] = {
        {-1, -1, -1, -1},
        {-1, 1, -1, 3},
        {0, -1, 2, -1},
        {-1, 0, 3, -1},
        {-1, -1, 1, 0},
        {3, 2, -1, -1},
        {1, -1, -1, 2}
    };
    // 记录各个拼图块路径的方向，0、1、2、3代表方向，-1代表不可走。
    bool vis[302][302];
};