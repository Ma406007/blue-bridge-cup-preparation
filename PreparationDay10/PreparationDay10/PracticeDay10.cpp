#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;

//��ʮ�������ű����������ʡ��C/C++��ѧB��

//��һ��
//int main() {
//	cout << 256 * 1024 * 1024 / 4 << endl;
//	return 0;
//}

//�ڶ���
//int arr[10] = { 0 };
//int ans[100005] = { 0 };
//int main() {
//	for (int i = 0; i <= 9; i++) {
//		arr[i] = 2021;
//	}
//	int i = 1;
//	for (i = 1; i <= 100004; i++) {
//		bool flag = true;
//		int tmp = i;
//		while (tmp) {
//			int index = tmp % 10;
//			tmp /= 10;
//			if (arr[index] == 0) {
//				flag = false;
//				break;
//			}
//			arr[index]--;
//			ans[i]++;
//		}
//		if (!flag) {
//			break;
//		}
//	}
//	cout << i - 1 << endl;
//	return 0;
//}

//������
struct Point{
	double x, y;
}point[25 * 25];//����ÿһ����

map<pair<double, double>, int> m;//����ÿһ��ֱ��,һ��б��k�ͽؾ�bȷ��һ��ֱ��
int main() {
	int cnt = 0;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 21; j++) {
			point[cnt].x = i;
			point[cnt].y = j;
			cnt++;
		}
	}
	int ans = 20 + 21;
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt; j++) {
			//�����ֱ����������ƽ�л򹲵�
			if (point[i].x == point[j].x || point[i].y == point[j].y) {
				continue;
			}
			double k = (point[j].y - point[i].y) / (point[j].x - point[i].x);
			double b = (point[j].x * point[i].y - point[i].x * point[j].y) / (point[j].x - point[i].x);
			if (m[{k, b}] == 0) {
				m[{k, b}]++;
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}