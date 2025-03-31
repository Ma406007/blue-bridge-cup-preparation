#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

//1.https://leetcode.cn/problems/percentage-of-letter-in-string/?envType=daily-question&envId=2025-03-31
class Solution01 {
public:
    int percentageLetter(string s, char letter) {
        int n = s.size();
        int cnt = 0;
        for (char ch : s) {
            if (ch == letter) {
                ++cnt;
            }
        }
        return 100 * cnt / n;
    }
};

//2.https://leetcode.cn/problems/count-primes/
/*
* 思路:
* 常规方法肯定会超时
* 此题思路之一是用埃氏筛,我们考虑这样一个事实:如果x是质数,那么大于x的x的倍数即2x,3x,...一定不是质数,因此我们可以从这里入手
* 我们设isPrime[i]表示数i是否为质数,如果是质数则为1,否则为0
* 从小到大遍历每个数,如果这个数为质数,则将其所有的倍数都标记为合数(除了该质数本身)即0,这样在运行结束的时候我们就能知道质数的个数
* 当然这里还可以继续优化:对于一个质数x如果按上文说的我们从2x开始标记其实是冗余的,应该直接从x*x开始标记
* 因为2x,3x,...这些数一定在x之前就被其他数的倍数标记过了,例如2的所有倍数,3的所有倍数等
*/
class Solution02 {
public:
    int countPrimes(int n) {
        vector<int> isPrime(n, 1);
        int ans = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                ans++;
                if ((long long)i * i < n) {
                    for (int j = i * i; j < n; j += i) {
                        isPrime[j] = 0;
                    }
                }
            }
        }
        return ans;
    }
};

//3.https://leetcode.cn/problems/number-of-students-doing-homework-at-a-given-time/
class Solution03 {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int ans = 0;
        for (int i = 0; i < startTime.size(); i++) {
            if (startTime[i] <= queryTime && endTime[i] >= queryTime) {
                ans++;
            }
        }
        return ans;
    }
};

//4.https://leetcode.cn/problems/unique-paths/
/*
* 由于我们每一步只能从向下或者向右移动一步,因此要想走到(i,j),如果向下走一步那么会从(i?1,j)走过来;如果向右走一步那么会从(i,j?1)走过来
* 故动态规划转移方程为:dp(i,j)=dp(i-1,j)+dp(i,j-1)
* 需要注意的是如果i=0或j=0,均不符合动态规划转移方程,我们需要忽略这两项
* 初始条件为dp(0,0)=1即从左上角走到左上角有且仅有一种方法
*/
class Solution04 {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));

        for (int i = 0; i < n; i++) {
            dp[0][i] = 1;
        }
        for (int j = 0; j < m; j++) {
            dp[j][0] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};