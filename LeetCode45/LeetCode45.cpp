#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
using namespace std;

// 1.https://leetcode.cn/problems/water-bottles-ii/?envType=daily-question&envId=2025-10-02
class Solution01 {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        if (numBottles < numExchange) {
            return numBottles;
        }
        return numExchange + maxBottlesDrunk(numBottles - numExchange + 1, numExchange + 1);
    }
};

// 2.https://leetcode.cn/problems/maximum-number-of-integers-to-choose-from-a-range-i/
class Solution02 {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int size = banned.size();
        set<int>st(banned.begin(), banned.end());

        int ans = 0;
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (st.find(i) == st.end() && (sum + i) <= maxSum) {
                sum += i;
                ans++;
            }
        }

        return ans;
    }
};

// 3.https://leetcode.cn/problems/destroying-asteroids/
class Solution03 {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());

        long long newMass = mass;
        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] <= newMass) {
                newMass += asteroids[i];
            }
            else {
                return false;
            }
        }

        return true;
    }
};

// 4.https://leetcode.cn/problems/rearrange-array-to-maximize-prefix-score/
class Solution04 {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());

        long long prefix = 0, ans = 0;
        for (int val : nums) {
            prefix += val;
            if (prefix > 0) {
                ans++;
            }
        }

        return ans;
    }
};

// 5.https://leetcode.cn/problems/largest-perimeter-triangle/
class Solution05 {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        if (nums.size() == 3) {
            if (nums[0] + nums[1] <= nums[2]) {
                return 0;
            }
            return nums[0] + nums[1] + nums[2];
        }

        int max = 0;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] + nums[i + 1] <= nums[i + 2]) {
                continue;
            }
            max = nums[i] + nums[i + 1] + nums[i + 2];
        }

        return max;
    }
};