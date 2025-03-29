#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

//力扣双周赛第一题
class Solution1 {
public:
    int reverseDegree(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 1; i <= n; i++) ans += (26 - (s[i - 1] - 'a')) * i;
        return ans;
    }
};

//力扣双周赛第二题
class Solution2 {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();

        //统计每一段的区间长度(连续0和连续1的长度都统计,一个0或一个1也算一个区间)
        vector<int> path;
        //快慢指针,快指针i代表一段区间的右区间,慢指针j代表一段区间的左区间
        for (int i = 0, j = 0; i < n; i++) {
            //指针i到末尾了无论指针j在哪都要计算区间长度,如果第i个元素与第i+1个元素不相等则计算区间长度
            if (i == n - 1 || s[i] != s[i + 1]) {
                //区间长度公式:右区间-左区间+1
                path.push_back(i - j + 1);
                //调整指针j至上一段区间的右区间,指针i继续向后移动,直到可以再次计算区间长度才调整指针j
                j = i + 1;
            }
        }

        int ans = 0;
        //第一个元素开始,如果第一个元素是0则指针i从下标0位置开始,由于连续0区间和连续1区间是相间的(即如果第一段区间是连续0区间,则下一段区间必是连续1区间),每次指针i需要移动两个下标,i+2不能超过path.size()
        for (int i = (s[0] == '0' ? 0 : 1); i + 2 < path.size(); i += 2) {
            //遍历vec选取相邻两段连续0区间得出这两段连续0区间的区间长度和的最大值(即局部最优解)以求得活跃区段的最大个数(即全局最优解)
            //因为题目要求是只能进行一次操作来获得最大的活跃区段数那就要保证选取的两段连续0区间的区间长度和是最大的以保证求得的活跃区段长度是最大的
            //(贪心算法的思想所在,所以这道题主要运用了贪心的思想)
            ans = max(ans, path[i] + path[i + 2]);
        }
        //在上述基础上加上原本存在的活跃区段即为答案
        for (auto& c : s) {
            if (c == '1') {
                ans++;
            }
        }
        return ans;
    }
};