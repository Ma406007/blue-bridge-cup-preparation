#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

//力扣第443场周赛第一题
//https://leetcode.cn/problems/minimum-cost-to-reach-every-position/
class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        vector<int> ans;

        //获取当前已经遍历到的元素中的最小值
        int minCost = cost[0];

        //与编号为0的人交换只能直接花费进行交换
        ans.push_back(cost[0]);
        for (int i = 1; i < cost.size(); i++) {
            minCost = min(minCost, cost[i]);

            //如果与当前的人交换所需费用小于当前已经遍历到的最小值(即最小花费在当前花费的前面)
            if (minCost <= cost[i]) {
                //采取策略:与最小花费的那个人交换然后和当前的人免费交换
                ans.push_back(minCost);
            }
        }
        return ans;
    }
};