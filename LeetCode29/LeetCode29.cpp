#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

// 1.https://leetcode.cn/problems/smallest-number-with-all-set-bits/
class Solution01 {
public:
    constexpr int bit_width(uint32_t n) {
        int width = 0;
        while (n) {
            ++width;
            n >>= 1;
        }

        return width;
    }

    // bit_width()：C++20，如果x非零，计算存储值x所需的位数，即1 + floor(log2(x))。如果x为零，返回零。
    int smallestNumber(int n) {
        return (1 << bit_width(uint32_t(n))) - 1;
    }
};

// 2.https://leetcode.cn/problems/number-of-bit-changes-to-make-two-integers-equal/
class Solution {
public:
    // __builtin_popcount()：返回输入数据中，二进制中‘1’的个数
    int minChanges(int n, int k) {
        return (n & k) != k ? -1 : __builtin_popcount(n ^ k);
    }
};

// 3.https://leetcode.cn/problems/sort-integers-by-the-number-of-1-bits/
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> bit(10001, 0);
        for (int i = 1; i <= 10000; ++i) {
            bit[i] = bit[i >> 1] + (i & 1);
        }
        sort(arr.begin(), arr.end(), [&](int x, int y) {
            if (bit[x] < bit[y]) {
                return true;
            }
            if (bit[x] > bit[y]) {
                return false;
            }
            return x < y;
            });

        return arr;
    }
};