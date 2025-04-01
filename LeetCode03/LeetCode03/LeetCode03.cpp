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
* ˼·:
* ���淽���϶��ᳬʱ
* ����˼·֮һ���ð���ɸ,���ǿ�������һ����ʵ:���x������,��ô����x��x�ı�����2x,3x,...һ����������,������ǿ��Դ���������
* ������isPrime[i]��ʾ��i�Ƿ�Ϊ����,�����������Ϊ1,����Ϊ0
* ��С�������ÿ����,��������Ϊ����,�������еı��������Ϊ����(���˸���������)��0,���������н�����ʱ�����Ǿ���֪�������ĸ���
* ��Ȼ���ﻹ���Լ����Ż�:����һ������x���������˵�����Ǵ�2x��ʼ�����ʵ�������,Ӧ��ֱ�Ӵ�x*x��ʼ���
* ��Ϊ2x,3x,...��Щ��һ����x֮ǰ�ͱ��������ı�����ǹ���,����2�����б���,3�����б�����
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
* ��������ÿһ��ֻ�ܴ����»��������ƶ�һ��,���Ҫ���ߵ�(i,j),���������һ����ô���(i?1,j)�߹���;���������һ����ô���(i,j?1)�߹���
* �ʶ�̬�滮ת�Ʒ���Ϊ:dp(i,j)=dp(i-1,j)+dp(i,j-1)
* ��Ҫע��������i=0��j=0,�������϶�̬�滮ת�Ʒ���,������Ҫ����������
* ��ʼ����Ϊdp(0,0)=1�������Ͻ��ߵ����Ͻ����ҽ���һ�ַ���
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