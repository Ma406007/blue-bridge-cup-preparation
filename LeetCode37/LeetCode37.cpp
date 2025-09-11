#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

// 1.https://leetcode.cn/problems/sort-vowels-in-a-string/?envType=daily-question&envId=2025-09-11
class Solution01 {
public:
    string YUANYIN = "AEIOUaeiou";

    bool check(char ch) {
        for (auto& c : YUANYIN) {
            if (ch == c) {
                return true;
            }
        }

        return false;
    }

    string sortVowels(string s) {
        string t;
        for (int i = 0; i < s.size(); i++) {
            if (check(s[i])) {
                t.push_back(s[i]);
            }
        }
        sort(t.begin(), t.end());

        string ans;
        int index = 0;
        for (int i = 0; i < s.size(); i++) {
            if (!check(s[i])) {
                ans.push_back(s[i]);
            }
            else {
                ans.push_back(t[index]);
                index++;
            }
        }

        return ans;
    }
};

// 2.https://leetcode.cn/problems/plates-between-candles/
class Solution02 {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> prefix(s.size());
        for (int i = 0, tmp = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                tmp++;
            }
            prefix[i] = tmp;
        }

        vector<int> left(s.size()), right(s.size());
        for (int i = 0, l = -1; i < s.size(); i++) {
            if (s[i] == '|') {
                l = i;
            }
            left[i] = l;
        }
        for (int i = s.size() - 1, r = -1; i >= 0; i--) {
            if (s[i] == '|') {
                r = i;
            }
            right[i] = r;
        }

        vector<int> ans;
        for (auto& query : queries) {
            int x = right[query[0]], y = left[query[1]];
            ans.emplace_back(x == -1 || y == -1 || x >= y ? 0 : prefix[y] - prefix[x]);
        }

        return ans;
    }
};

// 3.https://leetcode.cn/problems/can-you-eat-your-favorite-candy-on-your-favorite-day/
class Solution03 {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        vector<long long> prefix(candiesCount.size());
        prefix[0] = candiesCount[0];
        for (int i = 1; i < candiesCount.size(); i++) {
            prefix[i] = candiesCount[i] + prefix[i - 1];
        }

        vector<bool> ans;
        for (auto& query : queries) {
            int favoriteType = query[0], favoriteDay = query[1], dailyCap = query[2];

            long long x1 = favoriteDay + 1;
            long long y1 = (long long)(favoriteDay + 1) * dailyCap;
            long long x2 = (favoriteType == 0 ? 1 : prefix[favoriteType - 1] + 1);
            long long y2 = prefix[favoriteType];

            ans.emplace_back(!(x1 > y2 || y1 < x2));
        }

        return ans;
    }
};

// 4.https://leetcode.cn/problems/maximum-product-of-first-and-last-elements-of-a-subsequence/
class Solution04 {
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