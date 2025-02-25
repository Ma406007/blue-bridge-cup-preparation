// 1.https://www.luogu.com.cn/problem/P3156

//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	vector<int> students, calls;
//	for (int i = 0; i < n; i++) {
//		int tmp;
//		cin >> tmp;
//		students.push_back(tmp);
//	}
//	for (int i = 0; i < m; i++) {
//		int tmp;
//		cin >> tmp;
//		calls.push_back(tmp);
//	}
//	for (int i = 0; i < m; i++) {
//		cout << students[calls[i] - 1] << endl;
//	}
//	return 0;
//}

//2.https://www.luogu.com.cn/problem/P3613

//#include<iostream> 
//#include<map>
//using namespace std;
//
//map<int, map<int, int>> a;
//
//int main() {
//    int n, q, x, y, k, z;
//    cin >> n >> q;
//    for (int i = 1; i <= q; ++i) {
//        cin >> k >> x >> y;
//        if (k == 1) {
//            cin >> z;
//            a[x][y] = z;
//        }
//        else {
//            cout << a[x][y] << endl;
//        }
//    }
//    return 0;
//}