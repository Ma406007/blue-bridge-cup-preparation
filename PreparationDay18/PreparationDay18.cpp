#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>
using namespace std;

// 1.https://www.luogu.com.cn/problem/P1049
const int N = 1e8;
int m[N];
int dp[105][100005];
int main() {
	int V, n;
	cin >> V >> n;
	for (int i = 1; i <= n; i++) {
		cin >> m[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= V; j++) {
			if (j < m[i]) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - m[i]] + m[i]);
			}
		}
	}

	cout << V - dp[n][V] << endl;
	return 0;
}

// 2.https://www.luogu.com.cn/problem/P1048
const int N = 1e5;
int t[N], m[N];
int dp[105][1005];
int main() {
	int T, M;
	cin >> T >> M;
	for (int i = 1; i <= M; i++) {
		cin >> t[i] >> m[i];
	}

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= T; j++) {
			if (j < t[i]) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - t[i]] + m[i]);
			}
		}
	}

	cout << dp[M][T] << endl;
	return 0;
}