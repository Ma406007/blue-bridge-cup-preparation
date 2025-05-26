#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;

//1.https://leetcode.cn/problems/sum-of-all-subset-xor-totals/?envType=daily-question&envId=2025-05-26
class Solution01 {
public:
    int subsetXORSum(vector<int>& nums) {
        int or_ = 0;
        for (int x : nums) {
            or_ |= x;
        }
        return or_ << (nums.size() - 1);
    }
};

//2.https://leetcode.cn/problems/trapping-rain-water/
//方法一：最大值/最小值数组
class Solution02 {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left_Max(n, 0), right_Max(n, 0);

        int maxNum = 0;
        for (int i = 0; i < n; i++) {
            maxNum = max(maxNum, height[i]);
            left_Max[i] = maxNum;
        }
        maxNum = 0;
        for (int i = n - 1; i >= 0; i--) {
            maxNum = max(maxNum, height[i]);
            right_Max[i] = maxNum;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int tmp = min(left_Max[i], right_Max[i]);
            ans += tmp - height[i];
        }

        return ans;
    }
};

//3.https://leetcode.cn/problems/trapping-rain-water/
//方法二：单调栈
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> minus;
        int ans = 0;

        for (int i = 0; i < height.size(); i++) {
            while (!minus.empty() && height[i] > height[minus.top()]) {
                int top = minus.top();
                minus.pop();
                if (minus.empty()) {
                    break;
                }

                int left = minus.top();
                int currWidth = i - left - 1;
                int currHeight = min(height[left], height[i]) - height[top];

                ans += currWidth * currHeight;
            }

            minus.push(i);
        }

        return ans;
    }
};