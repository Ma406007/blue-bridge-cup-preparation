//1.https://www.luogu.com.cn/problem/P1996

//#include<iostream>
//using namespace std;
//
////记录出圈
//int ysf[101] = { 0 };
//int main() {
//	//初始化部分
//	int n, m;
//	cin >> n >> m;
//	int people[101] = { 0 };
//	for (int i = 1; i <= n; i++) {
//		people[i] = 1;
//	}
//
//	int sum = n;//圈内人数
//	int count = 1;//计数器
//	int cnt = 1;//people下标
//	int k = 1;//ysf下标
//	while (sum) {
//		//对应位置没人不报数,只调整下标
//		if (!people[cnt]) {
//			cnt++;
//		}
//		//有人就报数,调整下标并报数
//		else {
//			count++, cnt++;
//		}
//		//越界调整
//		if (cnt == n + 1) {
//			cnt = 1;
//		}
//		//数到m的出圈
//		if (count == m) {
//			//在圈内才能出圈
//			if (people[cnt]) {
//				people[cnt]--;
//				ysf[k++] = cnt;
//				count = 1, cnt++;//重置计数器,调整下标
//				sum--;//调整圈内总人数
//			}
//		}
//		//越界调整
//		if (cnt == n + 1) {
//			cnt = 1;
//		}
//	}
//	for (int i = 1; i <= k - 1; i++) {
//		cout << ysf[i] << ' ';
//	}
//	return 0;
//}

//2.https:www.luogu.com.cn/problem/P1160(哈希优化)

//#include<iostream>
//#include<list>
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//    list<int> students;
//    students.push_front(1);
//
//    //排队
//    //count为编号
//    int count = 2;
//    //从第二名同学开始排进队列
//    for (int i = 2; i <= n; i++) {
//        //创建迭代器便于查找并排队
//        list<int>::iterator it = students.begin();
//        //num为要插入到哪个同学的编号,ops为位置(左/右)
//        int num, ops;
//        cin >> num >> ops;
//
//        //找到编号为num的同学
//        while (*it != num) {
//            it++;
//        }
//        //需要排在左边
//        if (ops == 0) {
//            students.insert(it, count++);
//        }
//        //需要排在右边
//        else {
//            list<int>::iterator temp = it;
//            temp++;
//            students.insert(temp, count++);
//        }
//    }
//
//    //去掉几个同学
//    int m;
//    cin >> m;
//    for (int i = 1; i <= m; i++) {
//        list<int>::iterator it = students.begin();
//        //选择要去掉的同学的编号
//        int x;
//        cin >> x;
//
//        //找到编号为x的同学
//        while (*it != x) {
//            it++;
//            //没找到
//            if (it == students.end()) {
//                break;
//            }
//        }
//        //遍历到了就删除
//        if (it != students.end()) {
//            students.erase(it);
//        }
//        //遍历到了list的结尾说明该编号的同学不在队列中,不做任何操作
//        else {
//            continue;
//        }
//    }
//
//    //遍历
//    list<int>::iterator it = students.begin();
//    for (; it != students.end(); it++) {
//        if (next(it) == students.end()) {
//            cout << *it;
//        }
//        else {
//            cout << *it << ' ';
//        }
//    }
//    return 0;
//}

//3.https://www.luogu.com.cn/problem/P1540

//#include <vector>
//#include <iostream> 
//#include <algorithm>
//using namespace std;
//
//int main() {
//	int m, n, t, ans = 0;
//	cin >> m >> n;
//	vector<int> v;//用来表示内存
//	while (cin >> t) {
//		//如果不在内存中
//		if (find(v.begin(), v.end(), t) == v.end()) {
//			v.push_back(t);//加入内存
//			++ans;
//		}
//		//内存满了
//		if (v.size() > m) {
//			v.erase(v.begin());//把第一个单词删掉
//		}
//	}
//	cout << ans << endl;
//}

//4.https://www.luogu.com.cn/problem/P1618

//#include<iostream>
//using namespace std;
//int a[10], b1, b2, b3, l, k1, k2, k3, ans;
//int main() {
//    cin >> k1 >> k2 >> k3;
//    for (int b = 1; b <= 1000 / k3; ++b) {
//        b1 = b * k1;//求出三个数
//        b2 = b * k2;
//        b3 = b * k3;
//        if (b2 > 999 || b3 > 999) {
//            break;
//        }
//        for (int c = 1; c <= 3; ++c) {//将三个数进行分解，判断是否重复
//            a[b1 % 10]++;
//            b1 /= 10;
//        }
//        for (int c = 1; c <= 3; ++c) {
//            a[b2 % 10]++;
//            b2 /= 10;
//        }
//        for (int c = 1; c <= 3; ++c) {
//            a[b3 % 10]++;
//            b3 /= 10;
//        }
//        for (int c = 1; c <= 9; ++c) {
//            if (a[c] != 1) {
//                l = 1; break;
//            }
//        }
//        for (int c = 1; c <= 9; ++c) {
//            a[c] = 0;
//        }
//        if (!l) {
//            cout << b * k1 << " " << b * k2 << " " << b * k3 << endl;
//            ans++;
//        }
//        else {
//            l = 0;
//        }
//    }
//    if (!ans) {
//        cout << "No!!!";
//    }
//    return 0;
//}