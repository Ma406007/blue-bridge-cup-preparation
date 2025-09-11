#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// 1.https://leetcode.cn/problems/find-n-unique-integers-sum-up-to-zero/?envType=daily-question&envId=2025-09-07
class Solution01 {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        int m = 1;
        if (n % 2 == 0) {
            for (int i = 1; i <= n / 2; i++) {
                ans.emplace_back(m), ans.emplace_back(m * (-1));
                m++;
            }
        }
        else {
            ans.emplace_back(0);
            for (int i = 1; i <= (n - 1) / 2; i++) {
                ans.emplace_back(m), ans.emplace_back(m * (-1));
                m++;
            }
        }

        return ans;
    }
};

// 2.https://leetcode.cn/problems/special-array-ii/
class Solution02 {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> f(n);
        for (int i = 1; i < n; i++) {
            f[i] = f[i - 1];
            if (nums[i] % 2 == nums[i - 1] % 2) {
                f[i]++;
            }
        }

        vector<bool> ans;
        for (int i = 0; i < queries.size(); i++) {
            int right = queries[i][1], left = queries[i][0];
            ans.emplace_back(f[right] - f[left] == 0);
        }

        return ans;
    }
};

// 3.https://leetcode.cn/problems/maximum-absolute-sum-of-any-subarray/
class Solution03 {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int s = 0, mx = 0, mn = 0;
        for (auto& n : nums) {
            s += n;
            mx = max(mx, s);
            mn = min(mn, s);
        }

        return mx - mn;
    }
};

// 4.https://leetcode.cn/problems/longest-subsequence-with-limited-sum/
class Solution04 {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size(), m = queries.size();
        vector<int> f(n + 1);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            f[i + 1] = nums[i] + f[i];
        }

        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            ans[i] = upper_bound(f.begin(), f.end(), queries[i]) - f.begin() - 1;
        }

        return ans;
    }
};

// 5.https://leetcode.cn/problems/shift-distance-between-two-strings/
class Solution05 {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        const int SIGMA = 26;
        long long nxt_sum[SIGMA * 2 + 1]{}, pre_sum[SIGMA * 2 + 1]{};
        for (int i = 0; i < SIGMA * 2; i++) {
            nxt_sum[i + 1] = nxt_sum[i] + nextCost[i % SIGMA];
            pre_sum[i + 1] = pre_sum[i] + previousCost[i % SIGMA];
        }

        long long ans = 0;
        for (int i = 0; i < s.size(); i++) {
            int x = s[i] - 'a', y = t[i] - 'a';
            ans += min(nxt_sum[y < x ? y + SIGMA : y] - nxt_sum[x], pre_sum[(x < y ? x + SIGMA : x) + 1] - pre_sum[y + 1]);
        }
        return ans;
    }
};