<<<<<<< HEAD
//1.��ʮ�Ľ����ű�ʡ��C/C++��ѧB������B
//#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
//#include<cmath>
//using namespace std;
//
//int main() {
//	double n = 23333333, sum = 0;//nΪ01���ĳ���, sumΪ��Ϣ��
//	int o = 0;//0�ĸ���
//	//����0�ĳ��ִ�����1����0�ĳ��ִ���һ������01�����ȵ�һ��,���α���ֱ�������Ŀ������֪��Ϣ�ؾͿ��Եó�0��01���г��ֵĴ���
//	for (o = 0; o <= n / 2; o++) {
//		sum = 0;
//		//oΪ0�ĸ�����(n - o)Ϊ1�ĸ���
//		//������Ŀ������ʽ�ó���Ϣ��
//		sum -= o * (o / n) * log2(o / n) + (n - o) * ((n - o) / n) * log2((n - o) / n);
//		if (sum > 11625907.5 && sum < 11625907.6) {
//			cout << o << endl;
//			break;
//		}
//	}
//	return 0;
//}

//2.��ʮ�Ľ����ű�ʡ��C/C++��ѧB������C
//#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
//#include<cmath>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	int v_min = 1, v_max = 1e9;
//	while (n--) {
//		int a, b;
//		cin >> a >> b;
//
//		//��Ϊ B <= A / V < B + 1 (��Ϊ��ȡ����)
//		//���� (A / B) >= V > A / (B + 1)
//		//�� A % (B + 1) == 0 ʱ, Vmin = A / (B + 1) + 1
//		//�� A % (B + 1) != 0 ʱ, Vmin = A / (B + 1) + 1
//		//���� Vmin = A / (B + 1) + 1
//		//�� Vmax = (A / B), Vmin = A / (B + 1) + 1
//		v_min = max(v_min, a / (b + 1) + 1);
//		v_max = min(v_max, a / b);
//	}
//	cout << v_max << ' ' << v_min << endl;
//	return 0;
//}

//3.��ʮ�Ľ����ű�ʡ��C/C++��ѧB������D
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

const int N = 10;//��Ŀ�����������
int n;//�ɻ�����
struct Plane
{
    int t, d, l;
}p[N];//ÿ���ɻ�������,��װ��һ��������
bool st[N];//���ÿһ���ɻ��Ƿ���԰�ȫ����,��ʼ��Ϊfalse

//u:��¼��ǰ�Ѿ��ɹ�����ķɻ����� last:��¼��һ�ܷɻ���ɽ����ʱ��
bool dfs(int u, int last) {
    //�����������˵�����зɻ����ɰ�ȫ����,����true
    if (u == n) {
        return true;
    }

    for (int i = 0; i < n; i++) {
        int t = p[i].t, d = p[i].d, l = p[i].l;
        //�Ի�û�н���ķɻ������ж� �ж��Ƿ������ü����伴��lastʱ������Ȼû��ʱ:p[i].t+p[i].d>=last
        /*����������仰�����:
        * �����һ�ܷɻ���ɽ����ʱ�̴��ڵ�ǰ�ɻ�(δ����)��������ʱ��(��last>p[i].t+p[i].d),��ǰ�ɻ�(δ����)�Ͳ����ܽ�����(��ĿҪ��)
        * ����Ҫʹ��ǰ�ɻ���ʼ�������������һ�ܷɻ���ɽ����ʱ���ڵ�ǰ�ɻ�������ʱ��֮ǰ(��p[i].t+p[i].d>=last)
        * ��������������:
        * ����һ:��ǰ�ɻ�����δ����״̬(��ǰ��)
        * ������:��һ�ܷɻ�Ҫ�ڵ�ǰ�ɻ�������ʱ��ǰ��ɽ���(��Ҫ����)
        */
        if (!st[i] && t + d >= last) {
            //���Ϊ����
            st[i] = true;
            //�����ǰʱ��last��û��p[i].t(last<p[i].t,��һ�ܷɻ��ڵ�ǰ�ɻ����罵��ʱ��ǰ��ɽ���),��ǰ�ɻ�Ҫ�ȵ�p[i].t���ܿ�ʼ����(��Ŀ)
            //����ֱ����last��ʼ����(��ǰ������last��ʱ�����ϴ��ڵ��ڵ�ǰ�ɻ������罵��ʱ�̼�last>=p[i].t,��ʱ��ǰ�ɻ�ȡlastʱ�̿�ʼ����)
            //dfs����һ�ܷɻ����Խ���
            if (dfs(u + 1, max(last, t) + l)) {
                return true;
            }
            //����ߵ�����˵����ǰ����÷ɻ����ɰ�ȫ����
            st[i] = false;
        }
    }
    //������зɻ����Թ���,��Ȼ�޷���u+1��n��ȫ�������򷵻�false
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            int t, d, l;
            cin >> t >> d >> l;
            p[i] = { t, d, l };
        }
        memset(st, false, sizeof(bool));
        if (dfs(0, 0)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}