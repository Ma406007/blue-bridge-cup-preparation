#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//1.https://leetcode.cn/problems/form-array-by-concatenating-subarrays-of-another-array/
//我们依次枚举数组groups[i]并且使用变量k表示nums开始匹配查找的起点,初始时k=0
//如果匹配查找成功,那么将k设为查找到的下标加上groups[i]的长度;否则直接返回false,匹配到最后直接返回true
class Solution01 {
public:
    int find(vector<int>& nums, int k, vector<int>& g) {
        int m = g.size(), n = nums.size();
        if (k + g.size() > nums.size()) {
            return -1;
        }
        vector<int> pi(m);
        for (int i = 1, j = 0; i < m; i++) {
            while (j > 0 && g[i] != g[j]) {
                j = pi[j - 1];
            }
            if (g[i] == g[j]) {
                j++;
            }
            pi[i] = j;
        }
        for (int i = k, j = 0; i < n; i++) {
            while (j > 0 && nums[i] != g[j]) {
                j = pi[j - 1];
            }
            if (nums[i] == g[j]) {
                j++;
            }
            if (j == m) {
                return i - m + 1;
            }
        }
        return -1;
    }

    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < groups.size(); i++) {
            k = find(nums, k, groups[i]);
            if (k == -1) {
                return false;
            }
            k += groups[i].size();
        }
        return true;
    }
};