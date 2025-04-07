#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//第十三届蓝桥杯省赛C/C++大学B组A题
//int main() {
//	cout << 2 + 2 * 9 + 0 * 9 * 9 + 2 * 9 * 9 * 9 << endl;
//	return 0;
//}

//第十三届蓝桥杯省赛C/C++大学B组B题
//int main() {
//	cout << 14 << endl;
//	return 0;
//}

//第十三届蓝桥杯省赛C/C++大学B组C题
//long long a, b, n;
//long long weeks, days;//需要weeks个星期又days天
//long long today;//今天是星期today
//int main()
//{
//    cin >> a >> b >> n;
//    weeks = n / (a * 5 + b * 2);//获取星期
//    n -= weeks * (a * 5 + b * 2);//剩下天数
//    while (n > 0) {
//        if (today < 5) {//周一到周五
//            n -= a;
//        }
//        else {//周六到周日
//            n -= b;
//        }
//        today++;
//        today %= 7;//不会出现周八的情况
//        days++;
//    }
//    cout << weeks * 7 + days << endl;
//    return 0;
//}

//第十四届蓝桥杯省赛C/C++大学B组D题
int n;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {//遍历，输出结果
		cout << max(n - i, i - 1) * 2 << endl;
	}
}