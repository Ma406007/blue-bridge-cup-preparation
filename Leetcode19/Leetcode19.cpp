#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<unordered_map>
using namespace std;

// 1.https://leetcode.cn/problems/daily-temperatures/
class Solution01 {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        stack<int> maxTemp;
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            while (!maxTemp.empty() && temperatures[i] >= temperatures[maxTemp.top()]) {
                maxTemp.pop();
            }

            if (!maxTemp.empty()) {
                ans[i] = maxTemp.top() - i;
            }
            maxTemp.push(i);
        }
        return ans;
    }
};

// 2.https://leetcode.cn/problems/final-prices-with-a-special-discount-in-a-shop/
class Solution02 {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();

        stack<int> st;
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() > prices[i]) {
                st.pop();
            }

            if (!st.empty()) {
                ans[i] = prices[i] - st.top();
            }
            else {
                ans[i] = prices[i];
            }

            st.push(prices[i]);
        }
        return ans;
    }
};

// 3.https://leetcode.cn/problems/next-greater-element-i/
class Solution03 {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();

        unordered_map<int, int> hashmap;
        stack<int> st;
        vector<int> ans(n1);

        for (int i = 0; i < n2; i++) {
            while (!st.empty() && nums2[i] > st.top()) {
                hashmap[st.top()] = nums2[i];
                st.pop();
            }

            st.push(nums2[i]);
        }

        while (!st.empty()) {
            hashmap[st.top()] = -1;
            st.pop();
        }

        for (int i = 0; i < n1; i++) {
            ans[i] = hashmap[nums1[i]];
        }
        return ans;
    }
};