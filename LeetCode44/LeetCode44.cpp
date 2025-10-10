#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

// 1.https://leetcode.cn/problems/water-bottles/?envType=daily-question&envId=2025-10-01
class Solution01 {
public:
    int exchange(int numBottles, int numExchange) {
        if (numBottles < numExchange) {
            return 0;
        }
        return numBottles / numExchange + exchange(numBottles / numExchange + numBottles % numExchange, numExchange);
    }

    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        ans += exchange(numBottles, numExchange);

        return ans;
    }
};

// 2.https://leetcode.cn/problems/divide-an-array-into-subarrays-with-minimum-cost-i/
class Solution02 {
public:
    int minimumCost(vector<int>& nums) {
        int ans = nums[0];
        sort(nums.begin() + 1, nums.end());
        return ans + nums[1] + nums[2];
    }
};

// 3.https://leetcode.cn/problems/reduce-array-size-to-the-half/
class Solution03 {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int num : arr) {
            ++freq[num];
        }

        vector<int> occ;
        for (auto& pair : freq) {
            occ.push_back(pair.second);
        }
        sort(occ.begin(), occ.end(), greater<int>());

        int cnt = 0, ans = 0;
        for (int c : occ) {
            cnt += c;
            ans += 1;
            if (cnt * 2 >= arr.size()) {
                break;
            }
        }
        return ans;
    }
};

// 4.https://leetcode.cn/problems/maximum-units-on-a-truck/
class Solution04 {
public:
    int maximumUnits(vector<vector<int>>& b, int s) {
        sort(b.begin(), b.end(), [](const auto& L, const auto& R) {
            return L[1] > R[1];
            });

        int ans = 0, n = 0;
        for (int i = 0; i < b.size() && s > 0; i++) {
            n = min(s, b[i][0]);
            s -= n;
            ans += n * b[i][1];
        }

        return ans;
    }
};

// 5.https://leetcode.cn/problems/maximize-happiness-of-selected-children/
class Solution05 {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());

        long long ans = 0;
        int n = happiness.size();
        int flag = 0;
        for (int i = 0; i < k; i++) {
            ans += happiness[n - 1] - flag > 0 ? happiness[n - 1] -= flag : 0;
            flag++;
            happiness.pop_back();
            n--;
        }

        return ans;
    }
};