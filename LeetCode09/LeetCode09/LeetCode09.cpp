#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//1.https://leetcode.cn/problems/min-cost-climbing-stairs/?envType=study-plan-v2&envId=dynamic-programming
class Solution01 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, 0);

        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
        }

        return dp[n];
    }
};

//2.https://leetcode.cn/problems/house-robber/?envType=study-plan-v2&envId=dynamic-programming
class Solution02 {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        int n = nums.size();
        vector<int> dp(n, 0);

        dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }

        return dp[n - 1];
    }
};