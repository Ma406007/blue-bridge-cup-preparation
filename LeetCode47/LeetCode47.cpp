#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<numeric>
using namespace std;

// 1.https://leetcode.cn/problems/container-with-most-water/?envType=daily-question&envId=2025-10-04
class Solution01 {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while (l < r) {
            int area = min(height[l], height[r]) * (r - l);
            ans = max(ans, area);
            if (height[l] <= height[r]) {
                ++l;
            }
            else {
                --r;
            }
        }
        return ans;
    }
};

// 2.https://leetcode.cn/problems/compute-decimal-representation/
class Solution02 {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> nums;
        long long flag = 1;
        while (n) {
            int tmp = n % 10;
            if (tmp != 0) {
                nums.emplace_back(tmp * flag);
            }
            flag *= 10;

            n /= 10;
        }

        sort(nums.begin(), nums.end(), greater<int>());

        return nums;
    }
};

// 3.https://leetcode.cn/problems/split-array-with-minimum-difference/
class Solution03 {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        // 最长严格递增前缀
        long long pre = nums[0];
        int i = 1;
        while (i < n && nums[i] > nums[i - 1]) {
            pre += nums[i];
            i++;
        }

        // 最长严格递减后缀
        long long suf = nums[n - 1];
        int j = n - 2;
        while (j >= 0 && nums[j] > nums[j + 1]) {
            suf += nums[j];
            j--;
        }

        // 情况一
        if (i <= j) {
            return -1;
        }

        long long d = pre - suf;
        // 情况二
        if (i - 1 == j) {
            return abs(d);
        }

        // 情况三，suf 多算了一个 nums[i-1]，或者 pre 多算了一个 nums[i-1]
        return min(abs(d + nums[i - 1]), abs(d - nums[i - 1]));
    }
};