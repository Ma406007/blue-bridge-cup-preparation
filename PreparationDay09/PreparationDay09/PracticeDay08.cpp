#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;

//1.https://www.lanqiao.cn/problems/4124/learning/?page=1&first_category_id=1&tags=DFS,%E7%9C%81%E8%B5%9B&tag_relation=intersection
//int ans = 0;//方案数
////index为小朋友的下标,candy1为第一种糖果的数量,candy2为第二种糖果的数量
//void dfs(int index, int candy1, int candy2) {
//    //每个小朋友都已经分到糖果
//    if (index >= 7) {
//        //两种糖果都分完了
//        if (candy1 == 0 && candy2 == 0) {
//            ans++;
//        }
//        return;
//    }
//
//    for (int i = 0; i <= candy1; i++) {
//        for (int j = 0; j <= candy2; j++) {
//            //分给每个小朋友的两种糖果的个数范围
//            if (i + j >= 2 && i + j <= 5) {
//                dfs(index + 1, candy1 - i, candy2 - j);
//            }
//        }
//    }
//}
//int main() {
//    dfs(0, 9, 16);
//    cout << ans << endl;
//    return 0;
//}

//2.https://www.lanqiao.cn/problems/1372/learning/?page=1&first_category_id=1&tag_relation=intersection&problem_id=1372
//int main() {
//    int n, S, ans = INT_MAX;
//    int a[100005];
//    cin >> n >> S;
//    for (int i = 0; i < n; i++) {
//        cin >> a[i];
//    }
//    int i = 0, j = 0, sum = 0;
//    while (j < n) {
//        sum += a[j];
//        while (sum >= S) {
//            ans = min(ans, j - i + 1);
//            sum -= a[i];
//            i++;
//        }
//        j++;
//    }
//    if (ans == INT_MAX) {
//        cout << 0;
//    }
//    else {
//        cout << ans;
//    }
//    return 0;
//}

//3.https://www.lanqiao.cn/problems/3227/learning/?page=1&first_category_id=1&tag_relation=intersection&problem_id=3227
//const int N = 1e6 + 9;
//int a[N];
//int main() {
//    int n, m; cin >> n >> m;
//    int k = 0;
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            cin >> a[k++];
//        }
//    }
//    sort(a, a + k);
//    cout << a[k / 2];
//    return 0;
//}

//4.https://www.lanqiao.cn/problems/2080/learning/?page=1&first_category_id=1&tag_relation=intersection&problem_id=2080
//int a[200005];
//int main() {
//	int n;
//	cin >> n;
//	long long sum = 0, ans = 0;
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//		sum += a[i];
//	}
//	for (int i = 0; i < n; i++) {
//		sum -= a[i];
//		ans += sum * a[i];
//	}
//	cout << ans << endl;
//}

//5.https://www.lanqiao.cn/problems/1229/learning/?page=1&first_category_id=1&tags=%E9%93%BE%E8%A1%A8,%E6%A0%88,%E9%98%9F%E5%88%97,%E6%A0%91,%E5%A0%86,%E5%93%88%E5%B8%8C%E8%A1%A8&tag_relation=union
int main(void) {
    int n, i;
    string t1, t2, t3;
    stack<string> a;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> t1 >> t2;
        if (t1 == "in") {
            a.push(t2);
        }
        if (t1 == "out") {
            if (a.empty()) {
                goto end;
            }
            for (t3 = a.top(); t3 != t2; a.pop()) {
                if (a.empty()) {
                    goto end;
                }
                t3 = a.top();
            }
        }
    }
    if (a.empty()) {
    end:cout << "Empty";
    }
    else {
        cout << a.top();
    }
    return 0;
}

//6.https://www.lanqiao.cn/problems/2142/learning/?page=2&first_category_id=1&tags=%E9%93%BE%E8%A1%A8,%E6%A0%88,%E9%98%9F%E5%88%97,%E6%A0%91,%E5%A0%86,%E5%93%88%E5%B8%8C%E8%A1%A8&tag_relation=union
int a[26];
int main() {
    string s; cin >> s;
    int num = (int)s.size();
    for (int i = 0; i < num; ++i) {
        a[s[i] - 'A']++;
    }
    int m = 0;
    for (int i = 0; i < 26; ++i) {
        if (m < a[i]) {
            m = a[i];
        }
    }
    for (int i = 0; i < 26; ++i) {
        if (a[i] == m) {
            char c = i + 65;
            cout << c;
        }
    }
    return 0;
}