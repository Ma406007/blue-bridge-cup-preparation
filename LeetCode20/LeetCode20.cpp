#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// 1.https://leetcode.cn/problems/next-greater-element-ii/
class Solution01 {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = 0; i < n * 2 - 1; i++) {
            // 每次我们移动到数组中的一个新的位置i，我们就将当前单调栈中所有对应值小于nums[i]的下标弹出单调栈，这些值的下一个更大元素即为nums[i]
            while (!st.empty() && nums[st.top() % n] < nums[i % n]) {
                ans[st.top()] = nums[i % n];

                st.pop();
            }

            st.push(i % n);
        }
        return ans;
    }
};

// 2.https://leetcode.cn/problems/online-stock-span/
// 超时写法
class StockSpanner {
public:
    StockSpanner() {}

    int next(int price) {
        stock.emplace_back(price);

        for (int i = 0; i < stock.size() - 1; i++) {
            st.push(stock[i]);
        }

        int ans = 1;
        while (!st.empty() && st.top() <= stock[stock.size() - 1]) {
            ans++;

            st.pop();
        }

        while (!st.empty()) {
            st.pop();
        }

        return ans;
    }

private:
    stack<int> st;
    vector<int> stock;
};
//通过写法
class StockSpanner {
public:
    StockSpanner() {
        st.emplace(-1, INT_MAX);
        index = -1;
    }

    int next(int price) {
        index++;

        while (price >= st.top().second) {
            st.pop();
        }

        int ans = index - st.top().first;
        st.emplace(index, price);

        return ans;
    }

private:
    stack<pair<int, int>> st;
    int index;
};

// 3.https://leetcode.cn/problems/next-greater-node-in-linked-list/
class Solution03 {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        stack<pair<int, int>> st;
        vector<int> ans;
        int index = 0;

        while (head != nullptr) {
            ans.emplace_back(0);

            while (!st.empty() && head->val > st.top().first) {
                ans[st.top().second] = head->val;
                st.pop();
            }

            st.emplace(head->val, index++);

            head = head->next;
        }
        return ans;
    }
};