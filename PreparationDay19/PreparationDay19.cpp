#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>
using namespace std;

// 1.https://www.luogu.com.cn/problem/P1048
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

// 2.https://www.luogu.com.cn/problem/P1049
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

// 3.https://leetcode.cn/problems/length-of-the-longest-subsequence-that-sums-to-target/
class Solution03 {
public:
	int lengthOfLongestSubsequence(vector<int>& nums, int target) {
		int n = nums.size();
		vector<vector<int>> dp(n + 1, vector<int>(target + 1, INT_MIN));
		dp[0][0] = 0;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= target; ++j) {
				dp[i + 1][j] = dp[i][j];
				if (j - nums[i] >= 0) {
					dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - nums[i]] + 1);
				}
			}
		}

		return dp[n][target] > 0 ? dp[n][target] : -1;
	}
};

// 4.https://leetcode.cn/problems/target-sum/
class Solution04 {
public:
	int findTargetSumWays(vector<int>& nums, int target) {
		int sum = accumulate(nums.begin(), nums.end(), 0);

		int diff = sum - target;
		if (diff < 0 || diff % 2 != 0) {
			return 0;
		}

		int n = nums.size(), neg = diff / 2;
		vector<vector<int>> dp(n + 1, vector<int>(neg + 1, 0));
		dp[0][0] = 1;

		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= neg; j++) {
				dp[i][j] = dp[i - 1][j];
				if (j >= nums[i - 1]) {
					dp[i][j] += dp[i - 1][j - nums[i - 1]];
				}
			}
		}

		return dp[n][neg];
	}
};

// 5.https://www.luogu.com.cn/problem/P1150
int exchange(int n, int k) {
	if (n < k) {
		return 0;
	}

	return n / k + exchange(n / k + n % k, k);
}

int main() {
	int n, k;
	cin >> n >> k;

	cout << n + exchange(n, k) << endl;
	return 0;
}

// 6.https://www.luogu.com.cn/problem/P1151
int main() {
	int k;
	cin >> k;

	int flag = 0;
	for (int num = 10000; num <= 30000; num++) {
		string num_str = to_string(num);
		int sub1 = atoi(num_str.substr(0, 3).c_str());
		int sub2 = atoi(num_str.substr(1, 3).c_str());
		int sub3 = atoi(num_str.substr(2, 3).c_str());

		if (sub1 % k == 0 && sub2 % k == 0 && sub3 % k == 0) {
			cout << num << endl;
			flag = 1;
		}
	}

	if (!flag) {
		cout << "No" << endl;
	}

	return 0;
}

// 7.https://www.luogu.com.cn/problem/P1179
int main() {
	int L, R;
	cin >> L >> R;

	int ans = 0;
	for (int num = L; num <= R; num++) {
		string num_str = to_string(num);
		for (int i = 0; i < num_str.size(); i++) {
			if (num_str[i] == '2') {
				ans++;
			}
		}
	}

	cout << ans << endl;
	return 0;
}

// 8.https://www.luogu.com.cn/problem/P1317
int main()
{
	int a, b, ans = 0, l = 0, n;
	cin >> n >> a;

	for (int i = 1; i <= n; i++)
	{
		cin >> b;
		if (b < a) {
			l = 1;
		}
		if (b > a && l == 1) {
			ans++; l = 0;
		}
		a = b;
	}

	cout << ans;
	return 0;
}

// 9.https://www.luogu.com.cn/problem/P1401
using ll = long long;
int main() {
	ll xl, xu, yl, yu;
	cin >> xl >> xu >> yl >> yu;

	ll ans1 = xl * yl, ans2 = xl * yu, ans3 = xu * yl, ans4 = xu * yu;
	if (ans1 > INT_MAX || ans1 < INT_MIN || ans2 > INT_MAX || ans2 < INT_MIN
		|| ans3 > INT_MAX || ans3 < INT_MIN || ans4 > INT_MAX || ans4 < INT_MIN) {
		cout << "long long int";
	}
	else {
		cout << "int";
	}
	return 0;
}