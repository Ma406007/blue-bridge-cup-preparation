#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<unordered_map>
#include<queue>
#include<deque>
using namespace std;

// 1.https://leetcode.cn/problems/design-task-manager/?envType=daily-question&envId=2025-09-18
class TaskManager {
public:
    TaskManager(vector<vector<int>> tasks) {
        for (auto& task : tasks) {
            int userId = task[0], taskId = task[1], priority = task[2];
            taskInfo[taskId] = { priority, userId };
            heap.emplace(priority, taskId);
        }
    }

    void add(int userId, int taskId, int priority) {
        taskInfo[taskId] = { priority, userId };
        heap.emplace(priority, taskId);
    }

    void edit(int taskId, int newPriority) {
        if (taskInfo.find(taskId) != taskInfo.end()) {
            taskInfo[taskId].first = newPriority;
            heap.emplace(newPriority, taskId);
        }
    }

    void rmv(int taskId) {
        taskInfo.erase(taskId);
    }

    int execTop() {
        while (!heap.empty()) {
            auto [priority, taskId] = heap.top();
            heap.pop();

            if (taskInfo.find(taskId) != taskInfo.end() &&
                taskInfo[taskId].first == priority) {
                int userId = taskInfo[taskId].second;
                taskInfo.erase(taskId);
                return userId;
            }
        }
        return -1;
    }

private:
    unordered_map<int, pair<int, int>> taskInfo;
    priority_queue<pair<int, int>> heap;
};

// 2.https://leetcode.cn/problems/validate-stack-sequences/
class Solution02 {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = pushed.size();
        for (int i = 0, j = 0; i < n; i++) {
            st.emplace(pushed[i]);
            while (!st.empty() && st.top() == popped[j]) {
                st.pop();
                j++;
            }
        }
        return st.empty();
    }
};

// 3.https://leetcode.cn/problems/find-mirror-score-of-a-string/
class Solution03 {
public:
    long long calculateScore(string s) {
        stack<int> stk[26];
        long long ans = 0;
        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
            if (!stk[25 - c].empty()) {
                ans += i - stk[25 - c].top();
                stk[25 - c].pop();
            }
            else {
                stk[c].push(i);
            }
        }
        return ans;
    }
};

// 4.https://leetcode.cn/problems/minimum-string-length-after-removing-substrings/
class Solution04 {
public:
    int minLength(string s) {
        vector<int> st;
        for (char c : s) {
            st.push_back(c);
            int m = st.size();
            if (m >= 2 &&
                (st[m - 2] == 'A' && st[m - 1] == 'B' ||
                    st[m - 2] == 'C' && st[m - 1] == 'D')) {
                st.pop_back();
                st.pop_back();
            }
        }
        return st.size();
    }
};

// 5.https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/
class Solution05 {
public:
    string removeDuplicates(string s) {
        string stk;
        for (char ch : s) {
            if (!stk.empty() && stk.back() == ch) {
                stk.pop_back();
            }
            else {
                stk.push_back(ch);
            }
        }
        return stk;
    }
};

// 6.https://leetcode.cn/problems/make-the-string-great/
class Solution06 {
public:
    string makeGood(string s) {
        string ret;
        for (char ch : s) {
            if (!ret.empty() && tolower(ret.back()) == tolower(ch) && ret.back() != ch) {
                ret.pop_back();
            }
            else {
                ret.push_back(ch);
            }
        }
        return ret;
    }
};

// 7.https://leetcode.cn/problems/resulting-string-after-adjacent-removals/
class Solution07 {
public:
    bool is_consecutive(char x, char y) {
        int d = abs(x - y);
        return d == 1 || d == 25;
    }

    string resultingString(string s) {
        string st;
        for (char b : s) {
            if (!st.empty() && is_consecutive(b, st.back())) {
                st.pop_back();
            }
            else {
                st += b;
            }
        }
        return st;
    }
};