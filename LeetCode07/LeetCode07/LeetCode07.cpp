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
        //利用map将intervals数组中的所有区间存储起来,key为每个区间的左区间值,value为每个区间在intervals数组中的下标
        map<int, int> map;
        int index = 0;
        for (auto& v : intervals) {
            //map底层为红黑树,会自动排好序
            map[v[0]] = index++;
        }

        for (auto& v : intervals) {
            //lower_bound(begin, end, value):在从小到大的排好序的数组中,在数组的[begin, end)区间中二分查找第一个大于等于value的值并返回该数字的下标(或迭代器),如果不存在则返回end
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
        //set函数中的时间戳都是严格递增的,因此二元组列表中保存的时间戳也是严格递增的(已自动排好序)
        map[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp) {
        auto& pairs = map[key];
        //string({127}),一种构造方法,即对string对象插入一个值为127的char类型(127为char的最大值,在进行字符串比较时总是大于等于所有的字符串)
        pair<int, string> p = { timestamp, string({127}) };
        //由于已经自动排好序可以直接进行二分查找
        //upper_bound(begin, end, value):在从小到大的排好序的数组中,在数组的[begin, end)区间中二分查找第一个大于value的数,如果存在返回该数的下标(或迭代器),否则返回end
        auto i = upper_bound(pairs.begin(), pairs.end(), p);
        //找到了
        if (i != pairs.begin()) {
            return (i - 1)->second;
        }
        //没找到
        return "";
    }
};
/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */