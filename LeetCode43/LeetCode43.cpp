#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<ranges>
#include<map>
using namespace std;

// 1.https://leetcode.cn/problems/find-triangular-sum-of-an-array/?envType=daily-question&envId=2025-09-30
class Solution01 {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0] % 10;
        }

        vector<int> newNums;
        int newSize = n;
        for (int i = 0; i < n; i++) {
            for (int flag = 0; flag < newSize - 1; flag++) {
                int tmp = (nums[flag] + nums[flag + 1]) % 10;
                newNums.emplace_back(tmp);
            }

            nums.clear();
            nums = newNums;
            newNums.clear();

            newSize--;
        }

        return nums[0] % 10;
    }
};

// 2.https://leetcode.cn/problems/apple-redistribution-into-boxes/
class Solution02 {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = 0;
        for (int a : apple) {
            sum += a;
        }

        sort(capacity.begin(), capacity.end(), greater<int>());

        int ans = 0;
        for (int c : capacity) {
            if (sum <= 0) {
                break;
            }
            sum -= c;
            ans++;
        }

        return ans;
    }
};

// 3.https://leetcode.cn/problems/minimum-deletions-for-at-most-k-distinct-characters/
class Solution03 {
public:
    int minDeletion(string s, int k) {
        vector<int> cnt(26, 0);
        for (char b : s) {
            cnt[b - 'a']++;
        }

        sort(cnt.begin(), cnt.end());
        int ans = 0;
        for (int i = 0; i < 26 - k; i++) {
            ans += cnt[i];
        }
        return ans;
    }
};

// 4.https://leetcode.cn/problems/maximum-bags-with-full-capacity-of-rocks/
class Solution04 {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> vec(n);
        for (int i = 0; i < n; i++) {
            vec[i] = capacity[i] - rocks[i];
        }
        sort(vec.begin(), vec.end());

        for (int i = 0; i < n; i++) {
            int t = min(vec[i], additionalRocks);
            vec[i] -= t;
            additionalRocks -= t;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) if (vec[i] == 0) {
            ans++;
        }

        return ans;
    }
};

// 5.https://leetcode.cn/problems/maximum-ice-cream-bars/
class Solution05 {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());

        int ans = 0;
        for (int cost : costs) {
            coins -= cost;
            ans++;
            if (coins == 0) {
                break;
            }
            else if (coins < 0) {
                ans--;
                break;
            }
        }

        return ans;
    }
};

// 6.https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations/
class Solution06 {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num] += 1;
        }

        int ans = 0;
        for (int num : nums) {
            ans += num;
        }

        for (int i = -100; i < 0; ++i) {
            if (freq[i]) {
                int ops = min(k, freq[i]);
                ans += (-i) * ops * 2;
                freq[i] -= ops;
                freq[-i] += ops;
                k -= ops;
                if (k == 0) {
                    break;
                }
            }
        }
        if (k > 0 && k % 2 == 1 && !freq[0]) {
            for (int i = 1; i <= 100; ++i) {
                if (freq[i]) {
                    ans -= i * 2;
                    break;
                }
            }
        }
        return ans;
    }
};

// 7.https://leetcode.cn/problems/least-number-of-unique-integers-after-k-removals/
class Solution07 {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second;
    }

    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int size = arr.size();
        map<int, int>cnt;
        for (int i = 0; i < size; i++) {
            cnt[arr[i]]++;
        }

        vector<pair<int, int>>ans(cnt.begin(), cnt.end());
        sort(ans.begin(), ans.end(), cmp);

        int i = 0;
        for (i = 0; i < size; i++) {
            if (k >= ans[i].second) {
                k -= ans[i].second;
            }
            else {
                break;
            }
        }
        return ans.size() - i;
    }
};

// 8.https://leetcode.cn/problems/minimum-subsequence-in-non-increasing-order/
class Solution08 {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int total = 0;
        for (int num : nums) {
            total += num;
        }
        sort(nums.begin(), nums.end());

        vector<int> ans;
        int curr = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            curr += nums[i];
            ans.emplace_back(nums[i]);
            if (total - curr < curr) {
                break;
            }
        }

        return ans;
    }
};