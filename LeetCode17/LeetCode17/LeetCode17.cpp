#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<set>
using namespace std;

//1.https://leetcode.cn/problems/divisible-and-non-divisible-sums-difference/?envType=daily-question&envId=2025-05-27
class Solution01 {
public:
    int differenceOfSums(int n, int m) {
        int num1 = 0, num2 = 0;

        for (int i = 1; i <= n; i++) {
            if (i % m != 0) {
                num1 += i;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (i % m == 0) {
                num2 += i;
            }
        }

        return num1 - num2;
    }
};

//2.https://leetcode.cn/problems/stock-price-fluctuation/
class StockPrice {
public:
    StockPrice() {
        this->maxTimestamp = 0;
    }

    void update(int timestamp, int price) {
        maxTimestamp = max(maxTimestamp, timestamp);
        int prevPrice = timePriceMap.count(timestamp) ? timePriceMap[timestamp] : 0;
        timePriceMap[timestamp] = price;
        if (prevPrice > 0) {
            auto it = prices.find(prevPrice);
            if (it != prices.end()) {
                prices.erase(it);
            }
        }
        prices.emplace(price);
    }

    int current() {
        return timePriceMap[maxTimestamp];
    }

    int maximum() {
        return *prices.rbegin();
    }

    int minimum() {
        return *prices.begin();
    }
private:
    int maxTimestamp;
    unordered_map<int, int> timePriceMap;
    multiset<int> prices;
};

//3.https://leetcode.cn/problems/determine-the-winner-of-a-bowling-game/
class Solution03 {
public:
    int score(const vector<int>& player) {
        int res = 0;
        for (int i = 0; i < player.size(); i++) {
            if ((i > 0 && player[i - 1] == 10) || (i > 1 && player[i - 2] >= 10)) {
                res += 2 * player[i];
            }
            else {
                res += player[i];
            }
        }
        return res;
    }

    int isWinner(vector<int>& player1, vector<int>& player2) {
        int s1 = score(player1);
        int s2 = score(player2);
        return s1 == s2 ? 0 : s1 > s2 ? 1 : 2;
    }
};

