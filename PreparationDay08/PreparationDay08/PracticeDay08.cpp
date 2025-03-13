#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_set>
using namespace std;

//1.https://www.lanqiao.cn/problems/531/learning/?page=1&first_category_id=1&tags=%E5%86%92%E6%B3%A1%E6%8E%92%E5%BA%8F,%E6%8E%92%E5%BA%8F,%E5%BD%92%E5%B9%B6%E6%8E%92%E5%BA%8F,%E5%BF%AB%E9%80%9F%E6%8E%92%E5%BA%8F,%E6%A1%B6%E6%8E%92%E5%BA%8F&tag_relation=union
//struct student {
//    int id;
//    int c, m, e;
//    int sum;
//}s[305];
//
//bool cmd(student a, student b) {
//    if (a.sum > b.sum) return true;//先按照总成绩
//    else if (a.sum < b.sum) return false;
//    else if (a.c > b.c) return true;//在按照语文成绩
//    else if (a.c < b.c) return false;
//    else if (a.id < b.id) return true;//最后按照学号
//    else return false;
//}
//
//int main() {
//    int n;
//    cin >> n;
//    for (int i = 1; i <= n; i++) {
//        s[i].id = i;
//        cin >> s[i].c >> s[i].m >> s[i].e;
//        s[i].sum = s[i].c + s[i].m + s[i].e;
//    }
//    sort(s + 1, s + n + 1, cmd);
//    for (int i = 1; i <= 5; i++)
//        cout << s[i].id << " " << s[i].sum << endl;
//    return 0;
//}

//2.https://www.lanqiao.cn/problems/1206/learning/?page=1&first_category_id=1&tags=%E9%93%BE%E8%A1%A8,%E6%A0%88,%E9%98%9F%E5%88%97,%E6%A0%91,%E5%A0%86,%E5%93%88%E5%B8%8C%E8%A1%A8&tag_relation=union
//int main() {
//    unordered_set<string> str;
//    int n;
//    cin >> n;
//    for (int i = 0; i < n; i++) {
//        string s;
//        cin >> s;
//        str.insert(s);
//    }
//    cout << str.size() << endl;
//    return 0;
//}

//3.https://www.lanqiao.cn/problems/527/learning/?page=1&first_category_id=1&tags=GCD,LCM,%E8%B4%A8%E6%95%B0,%E8%B4%A8%E5%9B%A0%E5%AD%90%E5%88%86%E8%A7%A3,%E5%94%AF%E4%B8%80%E5%88%86%E8%A7%A3%E5%AE%9A%E7%90%86,%E5%BF%AB%E9%80%9F%E5%B9%82,%E9%80%86%E5%85%83,%E5%9F%83%E6%B0%8F%E7%AD%9B,%E7%BA%BF%E6%80%A7%E7%AD%9B,%E8%AE%A1%E6%95%B0%E9%97%AE%E9%A2%98&tag_relation=union
//bool cmp(int n) {
//    if (n < 2) {
//        return false;
//    }
//    else {
//        for (int i = 2; i * i <= n; i++) {
//            if (n % i == 0) {
//                return false;
//            }
//        }
//    }
//    return true;
//}
//int main() {
//    string a;
//    cin >> a;
//    int b[26] = { 0 };
//    int t = 0, maxn = 0, minn = 1;
//    int n = a.length();
//    for (int i = 0; i < n; i++) {
//        b[a[i] - 'a']++;
//    }
//    sort(b, b + 26);
//    for (int i = 0; i < 26; i++) {
//        if (b[i] != 0) {
//            minn = b[i];
//            break;
//        }
//    }
//    maxn = b[25];
//    if (cmp(maxn - minn)) {
//        cout << "Lucky Word" << endl << maxn - minn << endl;
//    }
//    else {
//        cout << "No Answer" << endl << '0' << endl;
//    }
//    return 0;
//}

//4.https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/
class Solution4 {
public:
    int maxProfit(vector<int>& prices) {
        int maxSum = 0;
        int i = 1;
        while (i < prices.size()) {
            //第二天跌
            if (prices[i - 1] > prices[i]) {
                continue;
            }
            //第二天涨
            else if (prices[i - 1] < prices[i]) {
                maxSum += prices[i] - prices[i - 1];
            }
            i++;
        }
        return maxSum;
    }
};

//5.https://leetcode.cn/problems/maximum-units-on-a-truck/
class Solution5 {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1];
            });
        int res = 0;
        for (auto& boxType : boxTypes) {
            int numberOfBoxes = boxType[0];
            int numberOfUnitsPerBox = boxType[1];
            if (numberOfBoxes < truckSize) {
                res += numberOfBoxes * numberOfUnitsPerBox;
                truckSize -= numberOfBoxes;
            }
            else {
                res += truckSize * numberOfUnitsPerBox;
                break;
            }
        }
        return res;
    }
};

//6.https://leetcode.cn/problems/number-of-islands/
class Solution6 {
public:
    void dfs(vector<vector<char>>& grid, int x, int y) {
        //污染数组,防止重复访问
        grid[x][y] = '0';
        //每一次都对x, y进行越界判定,否则不能进行递归
        if (x - 1 >= 0 && grid[x - 1][y] == '1') {
            dfs(grid, x - 1, y);
        }
        if (x + 1 < grid.size() && grid[x + 1][y] == '1') {
            dfs(grid, x + 1, y);
        }
        if (y - 1 >= 0 && grid[x][y - 1] == '1') {
            dfs(grid, x, y - 1);
        }
        if (y + 1 < grid[0].size() && grid[x][y + 1] == '1') {
            dfs(grid, x, y + 1);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) {
            return 0;
        }
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};

//7.https://leetcode.cn/problems/max-area-of-island/
class Solution7 {
public:
    int dfs(vector<vector<int>>& grid, int cur_i, int cur_j) {
        //越界和陆地判定
        if (cur_i < 0 || cur_j < 0 || cur_i == grid.size() || cur_j == grid[0].size() || grid[cur_i][cur_j] != 1) {
            return 0;
        }
        //污染数组,防止重复访问
        grid[cur_i][cur_j] = 0;
        int di[4] = { 0, 0, 1, -1 };
        int dj[4] = { 1, -1, 0, 0 };
        int ans = 1;
        for (int index = 0; index != 4; ++index) {
            int next_i = cur_i + di[index], next_j = cur_j + dj[index];
            ans += dfs(grid, next_i, next_j);
        }
        return ans;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0) {
            return 0;
        }

        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                ans = max(ans, dfs(grid, i, j));
            }
        }
        return ans;
    }
};

//8.https://www.luogu.com.cn/problem/P8218
//int num[100005] = { 0 };
//int ans[100005] = { 0 };
//int main() {
//    int n;
//    cin >> n;
//    for (int i = 1; i <= n; i++) {
//        cin >> num[i];
//    }
//    for (int i = 1; i <= n; i++) {
//        ans[i] = ans[i - 1] + num[i];
//    }
//    int m;
//    cin >> m;
//    for (int i = 1; i <= m; i++) {
//        int l, r;
//        cin >> l >> r;
//        cout << ans[r] - ans[l - 1] << endl;
//    }
//    return 0;
//}

//9.https://www.lanqiao.cn/problems/2361/learning/?page=1&first_category_id=1&tags=DFS,%E7%9C%81%E8%B5%9B&tag_relation=intersection
char s[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
char d[6] = {};//车牌
long long ans = 0;
//u为车牌的下标
void dfs(int u) {
    if (u == 6) {
        ans++;
        return;
    }

    for (int i = 0; i < (u >= 3 ? 10 : 16); i++) {
        d[u] = s[i];
        if (u >= 2 && d[u] == d[u - 1] && d[u] == d[u - 2]) {
            //连续三个位置的字符相同就跳过
            continue;
        }
        dfs(u + 1);
    }
}
int main() {
    dfs(0);
    cout << ans << endl;
    return 0;
}