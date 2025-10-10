#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

// 1.https://leetcode.cn/problems/taking-maximum-energy-from-the-mystic-dungeon/?envType=daily-question&envId=2025-10-10
class Solution01 {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        for (int i = energy.size() - k - 1; i >= 0; i--) {
            energy[i] += energy[i + k];
        }

        sort(energy.begin(), energy.end(), greater<int>());

        return energy[0];
    }
};

// 2.https://leetcode.cn/problems/find-the-minimum-amount-of-time-to-brew-potions/?envType=daily-question&envId=2025-10-09
class Solution02 {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<ll> times(n);

        for (int j = 0; j < m; j++) {
            ll cur_time = 0;
            for (int i = 0; i < n; i++) {
                cur_time = max(cur_time, times[i]) + skill[i] * mana[j];
            }
            times[n - 1] = cur_time;
            for (int i = n - 2; i >= 0; i--) {
                times[i] = times[i + 1] - skill[i + 1] * mana[j];
            }
        }

        return times[n - 1];
    }

private:
    using ll = long long;
};

// 3.https://leetcode.cn/problems/successful-pairs-of-spells-and-potions/?envType=daily-question&envId=2025-10-08
// 思路:
// 先对potions数组排好序(升序)，由题意可知我们需要遍历spells数组，找到potions中满足success / spells >= potions[i]中的第一个下标即可
class Solution03 {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        for (int& x : spells) {
            x = potions.end() - lower_bound(potions.begin(), potions.end(), 1.0 * success / x);
        }
        return spells;
    }
};