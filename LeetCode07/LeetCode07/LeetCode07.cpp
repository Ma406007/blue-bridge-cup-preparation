#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_set>
#include<map>
#include<unordered_map>
using namespace std;

//1.https://leetcode.cn/problems/minimum-operations-to-make-array-values-equal-to-k/?envType=daily-question&envId=2025-04-09
class Solution01 {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        if (k > nums[0]) {
            return -1;
        }

        int sum = 0;
        unordered_set<int> hs;
        for (auto& i : nums) {
            hs.insert(i);
        }

        for (auto& e : hs) {
            if (e != k) {
                sum++;
            }
        }

        return sum;
    }
};

//2.https://leetcode.cn/problems/find-right-interval/?envType=study-plan-v2&envId=binary-search
class Solution02 {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> ans;
        //����map��intervals�����е���������洢����,keyΪÿ�������������ֵ,valueΪÿ��������intervals�����е��±�
        map<int, int> map;
        int index = 0;
        for (auto& v : intervals) {
            //map�ײ�Ϊ�����,���Զ��ź���
            map[v[0]] = index++;
        }

        for (auto& v : intervals) {
            //lower_bound(begin, end, value):�ڴ�С������ź����������,�������[begin, end)�����ж��ֲ��ҵ�һ�����ڵ���value��ֵ�����ظ����ֵ��±�(�������),����������򷵻�end
            auto it = map.lower_bound(v[1]);
            if (it == map.end()) {
                ans.emplace_back(-1);
            }
            else {
                ans.emplace_back((*it).second);
            }
        }

        return ans;
    }
};

//3.https://leetcode.cn/problems/time-based-key-value-store/?envType=study-plan-v2&envId=binary-search
class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> map;

    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        //set�����е�ʱ��������ϸ������,��˶�Ԫ���б��б����ʱ���Ҳ���ϸ������(���Զ��ź���)
        map[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp) {
        auto& pairs = map[key];
        //string({127}),һ�ֹ��췽��,����string�������һ��ֵΪ127��char����(127Ϊchar�����ֵ,�ڽ����ַ����Ƚ�ʱ���Ǵ��ڵ������е��ַ���)
        pair<int, string> p = { timestamp, string({127}) };
        //�����Ѿ��Զ��ź������ֱ�ӽ��ж��ֲ���
        //upper_bound(begin, end, value):�ڴ�С������ź����������,�������[begin, end)�����ж��ֲ��ҵ�һ������value����,������ڷ��ظ������±�(�������),���򷵻�end
        auto i = upper_bound(pairs.begin(), pairs.end(), p);
        //�ҵ���
        if (i != pairs.begin()) {
            return (i - 1)->second;
        }
        //û�ҵ�
        return "";
    }
};
/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */