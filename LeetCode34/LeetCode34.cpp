#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<queue>
#include<deque>
using namespace std;

// 1.https://leetcode.cn/problems/find-the-minimum-area-to-cover-all-ones-i/?envType=daily-question&envId=2025-08-22
class Solution01 {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int max_i = 0, min_i = INT_MAX;
        int max_j = 0, min_j = INT_MAX;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j]) {
                    max_i = max(max_i, i);
                    min_i = min(min_i, i);
                    max_j = max(max_j, j);
                    min_j = min(min_j, j);
                }
            }
        }

        return (max_i - min_i + 1) * (max_j - min_j + 1);
    }
};

// 2.https://leetcode.cn/problems/count-number-of-trapezoids-i/
class Solution02 {
public:
    int MOD = 1e9 + 7;

    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int>mp;
        for (auto& x : points) {
            mp[x[1]]++;
        }

        long long  ans = 0, k = 0;
        for (auto& y : mp) {
            long long m = 1LL * y.second * (y.second - 1) / 2;
            ans += m * k;
            k += m;
        }

        return ans % MOD;
    }
};

// 3.https://leetcode.cn/problems/identify-the-largest-outlier-in-an-array/
class Solution03 {
public:
    int getLargestOutlier(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int total = 0;
        for (int x : nums) {
            cnt[x]++;
            total += x;
        }

        int ans = INT_MIN;
        for (int x : nums) {
            cnt[x]--;
            // 数组元素和为total，元素和为y，那么异常值x和元素和的关系为：2 * y = total - x
            if ((total - x) % 2 == 0 && cnt[(total - x) / 2] > 0) {
                ans = max(ans, x);
            }
            cnt[x]++;
        }


        return ans;
    }
};

// 4.https://leetcode.cn/problems/maximum-distance-in-arrays/
class Solution04 {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int ans = 0;
        int mn = INT_MAX / 2, mx = INT_MIN / 2; // 防止减法溢出
        for (auto& a : arrays) {
            ans = max({ ans, a.back() - mn, mx - a[0] });
            mn = min(mn, a[0]);
            mx = max(mx, a.back());
        }
        return ans;
    }
};

// 5.https://leetcode.cn/problems/count-number-of-bad-pairs/
class Solution05 {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long ans = n * (n - 1LL) / 2;
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            int tmp = nums[i] - i;
            ans -= cnt[tmp];
            cnt[tmp]++;
        }

        return ans;
    }
};

// 6.https://leetcode.cn/problems/best-sightseeing-pair/
class Solution06 {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int mx = values[0] + 0;
        int ans = 0;
        for (int i = 1; i < values.size(); i++) {
            ans = max(ans, mx + values[i] - i);
            mx = max(mx, values[i] + i);
        }

        return ans;
    }
};

// 7.https://leetcode.cn/problems/maximum-product-of-first-and-last-elements-of-a-subsequence/
class Solution07 {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        long long ans = LLONG_MIN;
        int mn = INT_MAX, mx = INT_MIN;
        for (int i = m - 1; i < nums.size(); i++) {
            // 维护左边 [0,i-m+1] 中的最小值和最大值
            int y = nums[i - m + 1];
            mn = min(mn, y);
            mx = max(mx, y);
            // 枚举右
            long long x = nums[i];
            ans = max({ ans, x * mn, x * mx });
        }
        return ans;
    }
};

// 8.https://leetcode.cn/problems/count-nice-pairs-in-an-array/
class Solution08 {
public:
    int countNicePairs(vector<int>& nums) {
        const int MOD = 1000000007;
        int res = 0;
        unordered_map<int, int> h;
        for (int i : nums) {
            int temp = i, j = 0;
            while (temp > 0) {
                j = j * 10 + temp % 10;
                temp /= 10;
            }
            res = (res + h[i - j]) % MOD;
            h[i - j]++;
        }
        return res;
    }
};