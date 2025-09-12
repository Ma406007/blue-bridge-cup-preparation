#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<cmath>
#include<numeric>
using namespace std;

// 1.https://leetcode.cn/problems/vowels-game-in-a-string/?envType=daily-question&envId=2025-09-12
class Solution {
public:
    bool doesAliceWin(string s) {
        for (auto& ch : s) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                return true;
            }
        }

        return false;
    }
};

// 2.https://leetcode.cn/problems/pairs-of-songs-with-total-durations-divisible-by-60/
class Solution02 {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> hashtable;
        int count = 0;
        for (int i = 0; i < time.size(); i++) {
            count += hashtable[(60 - time[i] % 60) % 60];
            hashtable[time[i] % 60]++;
        }

        return count;
    }
};

// 3.https://leetcode.cn/problems/count-pairs-that-form-a-complete-day-ii/
class Solution03 {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        unordered_map<LL, LL> hashtable;
        LL count = 0;
        for (auto& hour : hours) {
            count += hashtable[(24 - hour % 24) % 24];
            hashtable[hour % 24]++;
        }

        return count;
    }

private:
    using LL = long long;
};

// 4.https://leetcode.cn/problems/number-of-beautiful-pairs/
class Solution04 {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int ans = 0, cnt[10]{};
        for (int x : nums) {
            for (int y = 1; y < 10; y++) {
                if (cnt[y] && gcd(y, x % 10) == 1) {
                    ans += cnt[y];
                }
            }

            while (x >= 10) {
                x /= 10;
            }

            cnt[x]++;
        }

        return ans;
    }

private:
    int gcd(int n, int m) {
        if (n % m == 0) {
            return m;
        }

        return gcd(m, n % m);
    }
};

// 5.https://leetcode.cn/problems/count-pairs-of-similar-strings/
class Solution05 {
public:
    int similarPairs(vector<string>& words) {
        int ans = 0;
        unordered_map<int, int> hashtable;
        for (string word : words) {
            int mask = 0;
            for (char c : word) {
                mask |= 1 << (c - 'a');
            }

            ans += hashtable[mask]++;
        }

        return ans;
    }
};
