#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//��ʮ�������ű�ʡ��C/C++��ѧB��A��
//int main() {
//	cout << 2 + 2 * 9 + 0 * 9 * 9 + 2 * 9 * 9 * 9 << endl;
//	return 0;
//}

//��ʮ�������ű�ʡ��C/C++��ѧB��B��
//int main() {
//	cout << 14 << endl;
//	return 0;
//}

//��ʮ�������ű�ʡ��C/C++��ѧB��C��
//long long a, b, n;
//long long weeks, days;//��Ҫweeks��������days��
//long long today;//����������today
//int main()
//{
//    cin >> a >> b >> n;
//    weeks = n / (a * 5 + b * 2);//��ȡ����
//    n -= weeks * (a * 5 + b * 2);//ʣ������
//    while (n > 0) {
//        if (today < 5) {//��һ������
//            n -= a;
//        }
//        else {//����������
//            n -= b;
//        }
//        today++;
//        today %= 7;//��������ܰ˵����
//        days++;
//    }
//    cout << weeks * 7 + days << endl;
//    return 0;
//}

//��ʮ�Ľ����ű�ʡ��C/C++��ѧB��D��
int n;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {//������������
		cout << max(n - i, i - 1) * 2 << endl;
	}
}