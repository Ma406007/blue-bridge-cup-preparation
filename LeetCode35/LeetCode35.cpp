#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

// 1.https://leetcode.cn/problems/find-closest-person/?envType=daily-question&envId=2025-09-04
class Solution01 {
public:
    int findClosest(int x, int y, int z) {
        if (abs(z - x) < abs(z - y)) {
            return 1;
        }
        else if (abs(z - x) > abs(z - y)) {
            return 2;
        }
        return 0;
    }
};

// 2.https://leetcode.cn/problems/range-sum-query-immutable/
class NumArray {
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        sums.resize(n + 1);
        for (int i = 0; i < n; i++) {
            sums[i + 1] = sums[i] + nums[i];
        }

    }

    int sumRange(int left, int right) {
        return sums[right + 1] - sums[left];
    }

private:
    vector<int> sums;
};

// 3.https://leetcode.cn/problems/sum-of-variable-length-subarrays/
class Solution03 {
public:
    int subarraySum(vector<int>& nums) {
        vector<int> sums(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++) {
            sums[i + 1] = sums[i] + nums[i];
        }

        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int index = max(0, i - nums[i]);
            ans += sums[i + 1] - sums[index];
        }

        return ans;
    }
};

// 4.https://leetcode.cn/problems/count-vowel-strings-in-ranges/
class Solution04 {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefixSums(n + 1);
        for (int i = 0; i < n; i++) {
            int value = isVowelString(words[i]) ? 1 : 0;
            prefixSums[i + 1] = prefixSums[i] + value;
        }

        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int start = queries[i][0], end = queries[i][1];
            ans[i] = prefixSums[end + 1] - prefixSums[start];
        }
        return ans;
    }

    bool isVowelString(const string& word) {
        return isVowelLetter(word[0]) && isVowelLetter(word.back());
    }

    bool isVowelLetter(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};

// 5.https://leetcode.cn/problems/special-array-ii/
class Solution05 {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> f(n);
        for (int i = 1; i < n; i++) {
            f[i] = f[i - 1];
            // 如果 nums[i] 和 nums[i - 1] 的奇偶性一样，那么 i 就是一个断点
            // 一个询问区间如果包含了至少一个断点（左开右闭），那么它就不是特殊数组
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

// 6.https://leetcode.cn/problems/maximum-absolute-sum-of-any-subarray/
class Solution06 {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        // 绝对值在数学上的含义是表示两个点之间的距离，或者说两个数之间的差值，它永远等于大的数减去小的数
        // 因此在本题中可以视为子数组最大值减去子数组最小值的绝对值
        int s = 0, mx = 0, mn = 0;
        for (auto& x : nums) {
            s += x;
            mx = max(s, mx);
            mn = min(s, mn);
        }

        return mx - mn;
    }
};

// 7.https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-using-strategy/
class Solution07 {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> sum(n + 1), sum_sell(n + 1);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + prices[i] * strategy[i];
            sum_sell[i + 1] = sum_sell[i] + prices[i];
        }

        long long ans = sum[n];
        for (int i = k; i <= n; i++) {
            long long res = (sum[i - k]) + (sum[n] - sum[i]) + (sum_sell[i] - sum_sell[i - k / 2]);
            ans = max(res, ans);
        }

        return ans;
    }
};