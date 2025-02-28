//贪心算法(Greedy Algorithm)
//主要思想:只考虑当下最优解,不考虑未来,以此来获得全局最优解

//1.https://leetcode.cn/problems/assign-cookies/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class CookiesSolution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //排序
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0;
        int i = s.size() - 1, j = g.size() - 1;

        while (i >= 0 && j >= 0) {
            //饼干的尺寸大于等于孩子的胃口就分
            if (s[i] >= g[j]) {
                ans++;
                i--, j--;
            }
            else {
                j--;
            }
        }
        return ans;
    }
};

//2.https://leetcode.cn/problems/lemonade-change/

class LemonSolution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fee5 = 0;
        int fee10 = 0;
        int fee20 = 0;

        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) {
                fee5++;
            }
            if (bills[i] == 10) {
                fee10++;
                if (fee5 == 0) {
                    return false;
                }
                else {
                    fee5--;
                }
            }
            if (bills[i] == 20) {
                fee20++;
                if (fee10 == 0 && fee5 < 3) {
                    return false;
                }
                else if (fee5 == 0) {
                    return false;
                }
                if (fee5 >= 3 && fee10 == 0) {
                    fee5 -= 3;
                }
                if (fee5 && fee10) {
                    fee5--;
                    fee10--;
                }
            }
        }
        return true;
    }
};

//3.https://leetcode.cn/problems/merge-intervals/

class MergeSolution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        for (int i = 0; i < intervals.size(); i++) {
            while (i < intervals.size() - 1 && intervals[i + 1][0] <= intervals[i][1]) {
                intervals[i + 1][0] = intervals[i][0];
                intervals[i + 1][1] = max(intervals[i][1], intervals[i + 1][1]);
                i++;
            }
            ans.push_back(intervals[i]);
        }
        return ans;
    }
};

//4.https://leetcode.cn/problems/non-overlapping-intervals/

class IntervalsSolution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //特判
        if (intervals.empty()) {
            return 0;
        }

        sort(intervals.begin(), intervals.end(), [](const auto& u, const auto& v) {
            return u[1] < v[1];
            });
        int right = intervals[0][1];
        int ans = 1;

        //用总区间个数减去没有重叠的区间
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= right) {
                ans++;
                right = intervals[i][1];
            }
        }
        return intervals.size() - ans;
    }
};

//5.https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/

class BalloonsSolution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }

        sort(points.begin(), points.end(), [](const vector<int>& u, const vector<int>& v) {
            return u[1] < v[1];
            });

        int pos = points[0][1];
        int ans = 1;

        for (const vector<int>& balloon : points) {
            if (balloon[0] > pos) {
                pos = balloon[1];
                ++ans;
            }
        }
        return ans;
    }
};