#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<set>
using namespace std;

// 1.https://leetcode.cn/problems/design-a-number-container-system/?envType=daily-question&envId=2025-09-17
class NumberContainers {
public:
    void change(int index, int number) {
        // 移除旧数据
        auto it = index_to_number.find(index);
        if (it != index_to_number.end()) {
            number_to_indices[it->second].erase(index);
        }

        // 添加新数据
        index_to_number[index] = number;
        number_to_indices[number].insert(index);
    }

    int find(int number) {
        auto it = number_to_indices.find(number);
        return it == number_to_indices.end() || it->second.empty() ? -1 : *it->second.begin();
    }

private:
    unordered_map<int, int> index_to_number;
    unordered_map<int, set<int>> number_to_indices;
};

// 2.https://leetcode.cn/problems/build-an-array-with-stack-operations/
class Solution02 {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int cur = 0;
        vector<string> ans;
        for (int& v : target) {
            while (++cur < v) {
                ans.emplace_back("Push");
                ans.emplace_back("Pop");
            }
            ans.emplace_back("Push");
        }
        return ans;
    }
};

// 3.https://leetcode.cn/problems/backspace-string-compare/
class Solution03 {
public:
    bool backspaceCompare(string S, string T) {
        return build(S) == build(T);
    }

    string build(string str) {
        string ret;
        for (char ch : str) {
            if (ch != '#') {
                ret.push_back(ch);
            }
            else if (!ret.empty()) {
                ret.pop_back();
            }
        }
        return ret;
    }
};

// 4.https://leetcode.cn/problems/baseball-game/
class Solution04 {
public:
    int calPoints(vector<string>& ops) {
        int ret = 0;
        vector<int> points;
        for (auto& op : ops) {
            int n = points.size();
            switch (op[0]) {
            case '+':
                ret += points[n - 1] + points[n - 2];
                points.push_back(points[n - 1] + points[n - 2]);
                break;
            case 'D':
                ret += 2 * points[n - 1];
                points.push_back(2 * points[n - 1]);
                break;
            case 'C':
                ret -= points[n - 1];
                points.pop_back();
                break;
            default:
                ret += stoi(op);
                points.push_back(stoi(op));
                break;
            }
        }
        return ret;
    }
};

// 5.https://leetcode.cn/problems/removing-stars-from-a-string/
class Solution05 {
public:
    string removeStars(string s) {
        string ans;
        for (auto ch : s) {
            if (ch != '*') {
                ans.push_back(ch);
            }
            else {
                ans.pop_back();
            }
        }

        return ans;
    }
};

// 6.https://leetcode.cn/problems/design-browser-history/
class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        this->urls.push_back(homepage);
        this->currIndex = 0;
    }

    void visit(string url) {
        while (urls.size() > currIndex + 1) {
            urls.pop_back();
        }
        urls.push_back(url);
        this->currIndex++;
    }

    string back(int steps) {
        currIndex = max(currIndex - steps, 0);
        return urls[currIndex];
    }

    string forward(int steps) {
        currIndex = min(currIndex + steps, int(urls.size() - 1));
        return urls[currIndex];
    }

private:
    vector<string> urls;
    int currIndex;
};