#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<queue>
#include<deque>
#include<algorithm>
#include<set>
using namespace std;

// 1.https://leetcode.cn/problems/grid-teleportation-traversal/
class Solution01 {
public:
    int minMoves(vector<string>& matrix) {
        this->row = matrix.size(), this->col = matrix[0].size();
        if (matrix[row - 1][col - 1] == '#') {
            return -1;
        }

        vector<pair<int, int>> fly[26];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (isalpha(matrix[i][j])) {
                    // 总是会记录传送门alpha的最大坐标
                    fly[matrix[i][j] - 'A'].emplace_back(i, j);
                }
            }
        }

        vector<vector<int>> dis(row, vector<int>(col, INT_MAX));
        dis[0][0] = 0;

        deque<pair<int, int>> dq;
        dq.emplace_front(0, 0);

        while (!dq.empty()) {
            auto cur = dq.front();
            dq.pop_front();

            if (cur.first == row - 1 && cur.second == col - 1) {
                return dis[row - 1][col - 1];
            }

            char c = matrix[cur.first][cur.second];
            if (isalpha(c)) {
                for (auto [x, y] : fly[c - 'A']) {
                    // 如果是传送门，就传送到那里，fly总是会存储传送门的最大坐标
                    if (dis[x][y] > dis[cur.first][cur.second]) {
                        dis[x][y] = dis[cur.first][cur.second];
                        dq.emplace_front(x, y);
                    }
                }

                // 传送完后要清空，防止重复传送
                fly[c - 'A'].clear();
            }

            for (int i = 0; i < 4; i++) {
                int nx = cur.first + dx[i], ny = cur.second + dy[i];

                if (nx >= 0 && nx < row && ny >= 0 && ny < col && matrix[nx][ny] != '#' && dis[nx][ny] > dis[cur.first][cur.second] + 1) {
                    dis[nx][ny] = dis[cur.first][cur.second] + 1;
                    dq.emplace_back(nx, ny);
                }
            }
        }

        return -1;
    }

private:
    int row, col;
    int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
};

// 2.https://leetcode.cn/problems/6UEx57/
class Solution02 {
public:
    typedef pair<int, int> PII;
    int dist[110][110]; //需要更改传送带的次数。
    bool st[110][110];
    int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 }; //4个方向。上右下左。
    char g[4] = { '^', '>', 'v', '<' };

    int conveyorBelt(vector<string>& matrix, vector<int>& start, vector<int>& end) {
        int n = matrix.size(), m = matrix[0].size();

        deque<PII> q;

        q.push_back({ start[0], start[1] });
        memset(dist, -1, sizeof dist);
        dist[start[0]][start[1]] = 0;

        while (q.size())
        {
            auto t = q.front();
            q.pop_front();

            int x = t.first, y = t.second;
            //到终点，直接return
            if (x == end[0] && y == end[1]) {
                return dist[x][y];
            }

            if (st[x][y]) {
                continue;
            }
            st[x][y] = true;

            //printf("x = %d, y = %d, dist = %d\n", x, y, dist[x][y]);
            for (int i = 0; i < 4; i++)
            {
                int a = x + dx[i], b = y + dy[i];
                if (a < 0 || a >= n || b < 0 || b >= m || st[a][b]) {
                    continue;
                }

                if (g[i] == matrix[x][y]) //如果当前前进的方向 和传送带一个方向 加入队头
                {
                    q.push_front({ a, b });
                    dist[a][b] = dist[x][y];
                }
                else //前进方向和传送带不是一个方向，加入队尾。
                {
                    q.push_back({ a, b });
                    //如果当前点被更新过, 则更新为最小值。
                    if (dist[a][b] != -1) dist[a][b] = min(dist[a][b], dist[x][y] + 1);
                    else dist[a][b] = dist[x][y] + 1;
                }
            }
        }

        return 0;
    }
};

// 3.https://leetcode.cn/problems/two-sum/
class Solution03 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return { it->second, i };
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};

// 4.https://leetcode.cn/problems/largest-positive-integer-that-exists-with-its-negative/
class Solution04 {
public:
    int findMaxK(vector<int>& nums) {
        set<int> st;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            auto it = st.find(nums[i] * (-1));
            if (it != st.end()) {
                ans = max(ans, abs(nums[i]));
            }
            st.insert(nums[i]);
        }

        return !ans ? -1 : ans;
    }
};

// 5.https://leetcode.cn/problems/number-of-good-pairs/
class Solution05 {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }

        int ans = 0;
        for (auto& [k, v] : mp) {
            ans += v * (v - 1) / 2;
        }

        return ans;
    }
};

// 6.https://leetcode.cn/problems/number-of-good-pairs/
class Solution06 {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> cnt;
        for (int& x : nums) { // x = nums[j]
            ans += cnt[x]++;
        }
        return ans;
    }
};

// 7.https://leetcode.cn/problems/number-of-pairs-of-interchangeable-rectangles/
class Solution07 {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, int> mp;
        long long ans = 0;
        for (auto& rectangle : rectangles) {
            ans += mp[(double)rectangle[1] / (double)rectangle[0]]++;
        }

        return ans;
    }
};

// 8.https://leetcode.cn/problems/number-of-equivalent-domino-pairs/
class Solution08 {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ans = 0;
        int cnt[10][10]{};
        for (auto& d : dominoes) {
            auto [a, b] = minmax(d[0], d[1]); // 保证 a <= b
            ans += cnt[a][b]++;
        }
        return ans;
    }
};

// 9.https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/
class Solution09 {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int min_price = prices[0];
        for (auto& price : prices) {
            ans = max(ans, price - min_price);
            min_price = min(price, min_price);
        }

        return ans;
    }
};

// 10.https://leetcode.cn/problems/maximum-difference-between-increasing-elements/
class Solution10 {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = 0;
        int min_num = nums[0];
        for (auto& num : nums) {
            ans = max(ans, num - min_num);
            min_num = min(min_num, num);
        }

        return !ans ? -1 : ans;
    }
};

// 11.https://leetcode.cn/problems/contains-duplicate-ii/
class Solution11 {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            if (mp.find(x) != mp.end() && i - mp[x] <= k) {
                return true;
            }

            mp[x] = i;
        }

        return false;
    }
};

// 12.https://leetcode.cn/problems/minimum-consecutive-cards-to-pick-up/
class Solution12 {
public:
    int minimumCardPickup(vector<int>& cards) {
        int ans = INT_MAX;
        unordered_map<int, int> mp;
        for (int i = 0; i < cards.size(); i++) {
            if (mp.find(cards[i]) != mp.end()) {
                ans = min(ans, i - mp[cards[i]] + 1);
            }

            mp[cards[i]] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

// 13.https://leetcode.cn/problems/max-pair-sum-in-an-array/
class Solution13 {
public:
    int maxSum(vector<int>& nums) {
        int ans = -1;
        // 定义一个大小为 10 的整数数组 max_val，用于存储每个数字（0-9）作为最大数字时对应的最大数
        vector<int> max_val(10, INT_MIN);

        // 遍历数组 nums 中的每个数 v
        for (int v : nums) {
            // 初始化当前数 v 的最大数字为 0
            int max_d = 0;
            // 通过循环获取 v 每个数位上的数字，找到最大的数字
            for (int x = v; x; x /= 10)
                max_d = max(max_d, x % 10);
            // 更新最大和
            ans = max(ans, v + max_val[max_d]);
            // 更新当前最大数字对应的最大数
            max_val[max_d] = max(max_val[max_d], v);
        }
        // 返回最大和
        return ans;
    }
};

// 14.https://leetcode.cn/problems/max-sum-of-a-pair-with-equal-sum-of-digits/
// 同13题
class Solution14 {
public:
    int maximumSum(vector<int>& nums) {
        int ans = -1;
        vector<int> max_val(100, INT_MIN);

        for (auto& v : nums) {
            int max_d = 0;

            for (int x = v; x; x /= 10) {
                max_d += x % 10;
            }

            ans = max(ans, v + max_val[max_d]);
            max_val[max_d] = max(max_val[max_d], v);
        }

        return ans;
    }
};

// 15.https://leetcode.cn/problems/max-number-of-k-sum-pairs/
class Solution15 {
public:
    int maxOperations(vector<int>& nums, int k) {
        int cnt = 0;
        for (auto& num : nums) {
            if (k == num * 2) {
                cnt++;
            }
        }

        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] * 2 != k) {
                mp[k - nums[i]].emplace_back(i);
            }
        }

        int ans = cnt / 2;
        for (auto& num : nums) {
            if (mp.find(num) != mp.end()) {
                if (mp[num].size() > 0 && mp[k - num].size() > 0) {
                    ans++;

                    mp[num].pop_back(), mp[k - num].pop_back();
                }
            }
        }

        return ans;
    }
};

// 16.https://leetcode.cn/problems/pairs-with-sum-lcci/
class Solution16 {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i++) {
            vector<int> tmp;

            auto it = mp.find(target - nums[i]);
            if (it != mp.end() && it->second) {
                it->second--;
                tmp.emplace_back(nums[i]), tmp.emplace_back(target - nums[i]);
                ans.emplace_back(tmp);
            }
            else {
                mp[nums[i]]++;
            }
        }

        return ans;
    }
};