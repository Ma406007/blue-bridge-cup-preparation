//1.https://www.luogu.com.cn/problem/P1996

//#include<iostream>
//using namespace std;
//
////��¼��Ȧ
//int ysf[101] = { 0 };
//int main() {
//	//��ʼ������
//	int n, m;
//	cin >> n >> m;
//	int people[101] = { 0 };
//	for (int i = 1; i <= n; i++) {
//		people[i] = 1;
//	}
//
//	int sum = n;//Ȧ������
//	int count = 1;//������
//	int cnt = 1;//people�±�
//	int k = 1;//ysf�±�
//	while (sum) {
//		//��Ӧλ��û�˲�����,ֻ�����±�
//		if (!people[cnt]) {
//			cnt++;
//		}
//		//���˾ͱ���,�����±겢����
//		else {
//			count++, cnt++;
//		}
//		//Խ�����
//		if (cnt == n + 1) {
//			cnt = 1;
//		}
//		//����m�ĳ�Ȧ
//		if (count == m) {
//			//��Ȧ�ڲ��ܳ�Ȧ
//			if (people[cnt]) {
//				people[cnt]--;
//				ysf[k++] = cnt;
//				count = 1, cnt++;//���ü�����,�����±�
//				sum--;//����Ȧ��������
//			}
//		}
//		//Խ�����
//		if (cnt == n + 1) {
//			cnt = 1;
//		}
//	}
//	for (int i = 1; i <= k - 1; i++) {
//		cout << ysf[i] << ' ';
//	}
//	return 0;
//}

//2.https:www.luogu.com.cn/problem/P1160(��ϣ�Ż�)

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
//    //�Ŷ�
//    //countΪ���
//    int count = 2;
//    //�ӵڶ���ͬѧ��ʼ�Ž�����
//    for (int i = 2; i <= n; i++) {
//        //�������������ڲ��Ҳ��Ŷ�
//        list<int>::iterator it = students.begin();
//        //numΪҪ���뵽�ĸ�ͬѧ�ı��,opsΪλ��(��/��)
//        int num, ops;
//        cin >> num >> ops;
//
//        //�ҵ����Ϊnum��ͬѧ
//        while (*it != num) {
//            it++;
//        }
//        //��Ҫ�������
//        if (ops == 0) {
//            students.insert(it, count++);
//        }
//        //��Ҫ�����ұ�
//        else {
//            list<int>::iterator temp = it;
//            temp++;
//            students.insert(temp, count++);
//        }
//    }
//
//    //ȥ������ͬѧ
//    int m;
//    cin >> m;
//    for (int i = 1; i <= m; i++) {
//        list<int>::iterator it = students.begin();
//        //ѡ��Ҫȥ����ͬѧ�ı��
//        int x;
//        cin >> x;
//
//        //�ҵ����Ϊx��ͬѧ
//        while (*it != x) {
//            it++;
//            //û�ҵ�
//            if (it == students.end()) {
//                break;
//            }
//        }
//        //�������˾�ɾ��
//        if (it != students.end()) {
//            students.erase(it);
//        }
//        //��������list�Ľ�β˵���ñ�ŵ�ͬѧ���ڶ�����,�����κβ���
//        else {
//            continue;
//        }
//    }
//
//    //����
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
//	vector<int> v;//������ʾ�ڴ�
//	while (cin >> t) {
//		//��������ڴ���
//		if (find(v.begin(), v.end(), t) == v.end()) {
//			v.push_back(t);//�����ڴ�
//			++ans;
//		}
//		//�ڴ�����
//		if (v.size() > m) {
//			v.erase(v.begin());//�ѵ�һ������ɾ��
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
//        b1 = b * k1;//���������
//        b2 = b * k2;
//        b3 = b * k3;
//        if (b2 > 999 || b3 > 999) {
//            break;
//        }
//        for (int c = 1; c <= 3; ++c) {//�����������зֽ⣬�ж��Ƿ��ظ�
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