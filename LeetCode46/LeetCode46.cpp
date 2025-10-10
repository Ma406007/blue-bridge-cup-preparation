#include<iostream>
#include<vector>
#include<string>
#include<numeric>
#include<algorithm>
using namespace std;

// 1.https://leetcode.cn/problems/maximum-number-of-coins-you-can-get/
class Solution01 {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end(), greater<int>());

        int n = piles.size();
        int ans = 0;
        for (int i = 1; i <= 2 * n / 3 - 1; i += 2) {
            ans += piles[i];
        }

        return ans;
    }
};

// 2.https://leetcode.cn/problems/maximum-median-sum-of-subsequences-of-size-3/
class Solution02 {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());

        int n = nums.size();
        long long ans = 0;
        for (int i = 1; i <= 2 * n / 3 - 1; i += 2) {
            ans += nums[i];
        }

        return ans;
    }
};

// 3.https://leetcode.cn/problems/maximum-sum-with-at-most-k-elements/
class Solution03 {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        vector<int> a;
        for (int i = 0; i < grid.size(); i++) {
            auto& row = grid[i];
            sort(row.begin(), row.end(), greater<int>());
            a.insert(a.end(), row.begin(), row.begin() + limits[i]);
        }
        sort(a.begin(), a.end(), greater<int>());

        return accumulate(a.begin(), a.begin() + k, 0LL);
    }
};