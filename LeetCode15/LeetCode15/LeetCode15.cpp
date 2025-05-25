#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//1.https://leetcode.cn/problems/design-a-stack-with-increment-operation/
class CustomStack {
public:
    vector<int> stk;
    int top;

    CustomStack(int maxSize) {
        stk.resize(maxSize);
        top = -1;
    }

    void push(int x) {
        if (top != stk.size() - 1) {
            ++top;
            stk[top] = x;
        }
    }

    int pop() {
        if (top == -1) {
            return -1;
        }
        --top;
        return stk[top + 1];
    }

    void increment(int k, int val) {
        int lim = min(k, top + 1);
        for (int i = 0; i < lim; ++i) {
            stk[i] += val;
        }
    }
};

//2.https://leetcode.cn/problems/final-array-state-after-k-multiplication-operations-i/
class Solution02 {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while (k--) {
            auto iter = min_element(nums.begin(), nums.end());
            *iter *= multiplier;
        }
        return nums;
    }
};

//3.https://leetcode.cn/problems/find-the-sequence-of-strings-appeared-on-the-screen/
class Solution03 {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;
        string s;
        for (int c : target) {
            s += 'a';
            for (char j = 'a'; j <= c; j++) {
                s.back() = j;
                ans.push_back(s);
            }
        }
        return ans;
    }
};
