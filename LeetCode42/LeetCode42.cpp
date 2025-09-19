#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<stack>
using namespace std;

// 1.https://leetcode.cn/problems/design-spreadsheet/?envType=daily-question&envId=2025-09-19
class Spreadsheet01 {
public:
    Spreadsheet(int rows) {
        this->excel = vector<vector<int>>(rows + 1, vector<int>(26));
    }

    void setCell(string cell, int value) {
        auto [x, y] = getPos(cell);
        excel[x][y] = value;
    }

    void resetCell(string cell) {
        auto [x, y] = getPos(cell);
        excel[x][y] = 0;
    }

    int getValue(string formula) {
        int i = formula.find('+');
        string cell1 = formula.substr(1, i - 1);
        string cell2 = formula.substr(i + 1);
        return getCellVal(cell1) + getCellVal(cell2);
    }

private:
    vector<vector<int>> excel;
    int row;

    pair<int, int> getPos(const string& cell) {
        int x = stoi(cell.substr(1));
        int y = cell[0] - 'A';
        return { x, y };
    }

    int getCellVal(string& cell) {
        if (isalpha(cell[0])) {
            auto [x, y] = getPos(cell);
            return excel[x][y];
        }
        else {
            return stoi(cell);
        }
    }
};

class Spreadsheet02 {
public:
    Spreadsheet(int) {}

    void setCell(string cell, int value) {
        cellValues[cell] = value;
    }

    void resetCell(string cell) {
        cellValues.erase(cell);
    }

    int getValue(string formula) {
        int i = formula.find('+');
        string cell1 = formula.substr(1, i - 1);
        string cell2 = formula.substr(i + 1);
        return (isalpha(cell1[0]) ? cellValues[cell1] : stoi(cell1)) +
            (isalpha(cell2[0]) ? cellValues[cell2] : stoi(cell2));
    }

private:
    unordered_map<string, int> cellValues;
};

// 2.https://leetcode.cn/problems/valid-parentheses/
class Solution02 {
public:
    bool isValid(string s) {
        if (s.length() % 2) { // s 长度必须是偶数
            return false;
        }
        stack<char> st;
        for (char c : s) {
            if (c == '(') {
                st.push(')'); // 入栈对应的右括号
            }
            else if (c == '[') {
                st.push(']');
            }
            else if (c == '{') {
                st.push('}');
            }
            else { // c 是右括号
                if (st.empty() || st.top() != c) {
                    return false; // 没有左括号，或者左括号类型不对
                }
                st.pop(); // 出栈
            }
        }
        return st.empty(); // 所有左括号必须匹配完毕
    }
};

// 3.https://leetcode.cn/problems/number-of-recent-calls/
class RecentCounter {
public:
    RecentCounter() {}

    int ping(int t) {
        q.push(t);
        while (q.front() < t - 3000) {
            q.pop();
        }

        return q.size();
    }

private:
    queue<int> q;
};

// 4.https://leetcode.cn/problems/climbing-stairs/
class Solution04 {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1, dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

// 5.https://leetcode.cn/problems/min-cost-climbing-stairs/
class Solution05 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 1);
        for (int i = 2; i <= cost.size(); i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }

        return dp[cost.size()];
    }
};

// 6.https://leetcode.cn/problems/house-robber/
class Solution06 {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        vector<int> dp(nums.size());
        dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }

        return dp[nums.size() - 1];
    }
};

// 7.https://leetcode.cn/problems/house-robber-ii/
class Solution07 {
public:
    int robRange(vector<int>& nums, int start, int end) {
        vector<int> dp(end + 1);
        dp[start] = nums[start], dp[start + 1] = max(nums[start], nums[start + 1]);

        for (int i = 2; i <= end; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }

        return dp[end];
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        else if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }

        return max(robRange(nums, 0, nums.size() - 2), robRange(nums, 1, nums.size() - 1));
    }
};