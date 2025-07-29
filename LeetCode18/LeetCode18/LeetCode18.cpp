#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//1.https://leetcode.cn/problems/number-of-even-and-odd-bits/
class Solution01 {
public:
    vector<int> evenOddBit(int n) {
        vector<int> ans(2);
        for (int i = 0; n; n >>= 1) {
            ans[i] += n & 1;
            i ^= 1; // «–ªª∆Ê≈º
        }
        return ans;
    }
};

//2.https://leetcode.cn/problems/maximum-ascending-subarray-sum/
class Solution02 {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = 0, t = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0 || nums[i] > nums[i - 1]) {
                t += nums[i];
                ans = max(ans, t);
            }
            else {
                t = nums[i];
            }
        }
        return ans;
    }
};