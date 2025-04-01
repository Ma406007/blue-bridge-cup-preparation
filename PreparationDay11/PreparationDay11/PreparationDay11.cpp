//1.第十四届蓝桥杯省赛C/C++大学B组试题B
//#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
//#include<cmath>
//using namespace std;
//
//int main() {
//	double n = 23333333, sum = 0;//n为01串的长度, sum为信息熵
//	int o = 0;//0的个数
//	//由于0的出现次数比1少则0的出现次数一定少于01串长度的一半,依次遍历直到求出题目给出已知信息熵就可以得出0在01串中出现的次数
//	for (o = 0; o <= n / 2; o++) {
//		sum = 0;
//		//o为0的个数则(n - o)为1的个数
//		//根据题目所给公式得出信息熵
//		sum -= o * (o / n) * log2(o / n) + (n - o) * ((n - o) / n) * log2((n - o) / n);
//		if (sum > 11625907.5 && sum < 11625907.6) {
//			cout << o << endl;
//			break;
//		}
//	}
//	return 0;
//}

//2.第十四届蓝桥杯省赛C/C++大学B组试题C
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
//		//因为 B <= A / V < B + 1 (因为“取整”)
//		//所以 (A / B) >= V > A / (B + 1)
//		//当 A % (B + 1) == 0 时, Vmin = A / (B + 1) + 1
//		//当 A % (B + 1) != 0 时, Vmin = A / (B + 1) + 1
//		//所以 Vmin = A / (B + 1) + 1
//		//则 Vmax = (A / B), Vmin = A / (B + 1) + 1
//		v_min = max(v_min, a / (b + 1) + 1);
//		v_max = min(v_max, a / b);
//	}
//	cout << v_max << ' ' << v_min << endl;
//	return 0;
//}

//3.第十四届蓝桥杯省赛C/C++大学B组试题D
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

const int N = 10;//题目所给最大案例数
int n;//飞机架数
struct Plane
{
    int t, d, l;
}p[N];//每个飞机的属性,封装到一个数组内
bool st[N];//检查每一个飞机是否可以安全降落,初始均为false

//u:记录当前已经成功降落的飞机数量 last:记录上一架飞机完成降落的时间
bool dfs(int u, int last) {
    //如果条件成立说明所有飞机均可安全降落,返回true
    if (u == n) {
        return true;
    }

    for (int i = 0; i < n; i++) {
        int t = p[i].t, d = p[i].d, l = p[i].l;
        //对还没有降落的飞机进行判断 判断是否还能来得及降落即在last时刻它依然没超时:p[i].t + p[i].d >= last
        if (!st[i] && t + d >= last) {
            //标记为降落
            st[i] = true;
            //如果当前时间last还没到p[i].t,飞机要等到p[i].t才能开始降落
            //否则直接在last开始降落
            //dfs让下一架飞机尝试降落
            if (dfs(u + 1, max(last, t) + l)) {
                return true;
            }
            //如果走到这里说明当前情况该飞机不可安全降落
            st[i] = false;
        }
    }
    //如果所有飞机都试过了,依然无法让u+1到n架全部降落则返回false
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