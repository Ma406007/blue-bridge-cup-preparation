#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//1.https://leetcode.cn/problems/delete-and-earn/
class Solution01 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }

        vector<int> dp(n, 0);
        dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }

        return dp[n - 1];
    }

    int deleteAndEarn(vector<int>& nums) {
        int maxNum = 0;
        for (auto& num : nums) {
            maxNum = max(maxNum, num);
        }

        vector<int> sum(maxNum + 1, 0);
        for (auto& num : nums) {
            sum[num] += num;
        }

        return rob(sum);
    }
};

//2.https://leetcode.cn/problems/count-number-of-ways-to-place-houses/
class Solution {
public:
    const int MOD = 1e9 + 7;

    int countHousePlacements(int n) {
        //定义f[i]表示前i个地块的放置方案数,其中第i个地块可以放房子也可以不放房子
        vector<long long> f(n + 1);
        //边界条件为
        //f[0]=1,空只有一中选择,即不放房子
        //f[1]=2,放与不放两种方案
        f[0] = 1, f[1] = 2;

        //考虑第i个地块:
        //若不放房子,那么第i−1个地块可放可不放,则有f[i]=f[i−1]
        //若放房子,那么第i−1个地块无法放房子,第i−2个地块可放可不放,则有f[i]=f[i−2]
        //因此有:f[i]=f[i−1]+f[i−2](斐波那契数列递推式)
        for (int i = 2; i <= n; ++i) {
            f[i] = (f[i - 1] + f[i - 2]) % MOD;
        }

        return f[n] * f[n] % MOD;
    }
};

//3.https://leetcode.cn/problems/house-robber-ii/
class Solution03 {
public:
    int robRange(vector<int>& nums, int start, int end) {
        vector<int> dp(end + 1, 0);
        dp[start] = nums[start], dp[start + 1] = max(nums[start], nums[start + 1]);

        for (int i = start + 2; i <= end; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }

        return dp[end];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        //如果只有一个房子就抢这个房子
        if (n == 1) {
            return nums[0];
        }
        //如果有两个房子就抢这两个房子之间的最大值
        if (n == 2) {
            return max(nums[0], nums[1]);
        }

        //由于nums是首尾相连的:
        //抢了第一个房子之后就不能再抢最后一个房子,只能抢倒数第二个房子(抢劫范围:(0,n-2))
        //要抢最后一个房子就不能抢第一个房子,需要从第二个房子开始抢(抢劫范围:(1,n-1))
        //分别将抢劫范围代入打家劫舍模板求出两者最大值即可
        return max(robRange(nums, 0, n - 2), robRange(nums, 1, n - 1));
    }
};