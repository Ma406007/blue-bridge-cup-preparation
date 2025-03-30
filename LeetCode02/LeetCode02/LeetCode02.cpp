#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

//���۵�443��������һ��
//https://leetcode.cn/problems/minimum-cost-to-reach-every-position/
class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        vector<int> ans;

        //��ȡ��ǰ�Ѿ���������Ԫ���е���Сֵ
        int minCost = cost[0];

        //����Ϊ0���˽���ֻ��ֱ�ӻ��ѽ��н���
        ans.push_back(cost[0]);
        for (int i = 1; i < cost.size(); i++) {
            minCost = min(minCost, cost[i]);

            //����뵱ǰ���˽����������С�ڵ�ǰ�Ѿ�����������Сֵ(����С�����ڵ�ǰ���ѵ�ǰ��)
            if (minCost <= cost[i]) {
                //��ȡ����:����С���ѵ��Ǹ��˽���Ȼ��͵�ǰ������ѽ���
                ans.push_back(minCost);
            }
        }
        return ans;
    }
};