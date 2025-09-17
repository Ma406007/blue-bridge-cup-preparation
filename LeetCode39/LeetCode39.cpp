#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
using namespace std;

// 1.https://leetcode.cn/problems/maximum-number-of-words-you-can-type/?envType=daily-question&envId=2025-09-16
class Solution01 {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken;
        for (char ch : brokenLetters) {
            broken.insert(ch);
        }
        int res = 0;
        bool flag = true;
        for (char ch : text) {
            if (ch == ' ') {
                if (flag) {
                    ++res;
                }
                flag = true;
            }
            else if (broken.count(ch)) {
                flag = false;
            }
        }

        if (flag) {
            ++res;
        }
        return res;
    }
};

// 2.https://leetcode.cn/problems/find-most-frequent-vowel-and-consonant/?envType=daily-question&envId=2025-09-16
class Solution02 {
public:
    bool is_vowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxFreqSum(string s) {
        unordered_map<char, int> mp;
        for (auto ch : s) {
            mp[ch]++;
        }
        int vowel = 0, consonant = 0;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (is_vowel(ch)) {
                vowel = max(vowel, mp[ch]);
            }
            else {
                consonant = max(consonant, mp[ch]);
            }
        }
        return vowel + consonant;
    }
};

// 3.https://leetcode.cn/problems/binary-subarrays-with-sum/class Solution {
class Solution03 {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum = 0;
        unordered_map<int, int> cnt;
        int ans = 0;
        for (int num : nums) {
            cnt[sum]++;
            sum += num;
            ans += cnt[sum - goal];
        }

        return ans;
    }
};

// 4.https://leetcode.cn/problems/subarray-sum-equals-k/
class Solution04 {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int, int> cnt;
        int ans = 0;
        for (int num : nums) {
            cnt[sum]++;
            sum += num;
            ans += cnt[sum - k];
        }

        return ans;
    }
};

// 5.https://leetcode.cn/problems/number-of-sub-arrays-with-odd-sum/
class Solution05 {
public:
    int numOfSubarrays(vector<int>& arr) {
        int sum = 0;
        int cnt[2]{ 1, 0 };
        int ans = 0;
        for (int num : arr) {
            sum += num;
            cnt[sum % 2]++;
            ans = (ans + cnt[1 - sum % 2]) % MOD;
        }

        return ans;
    }

private:
    const int MOD = 1E9 + 7;
};

// 6.https://leetcode.cn/problems/subarray-sums-divisible-by-k/
class Solution06 {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        int ans = 0;
        for (int num : nums) {
            sum += num;
            int key = (sum % k + k) % k;
            ans += cnt[key];
            cnt[key]++;
        }

        return ans;
    }
};