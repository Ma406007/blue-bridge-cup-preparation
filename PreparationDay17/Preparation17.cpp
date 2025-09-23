#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;

// 1.https://www.luogu.com.cn/problem/P1002
const int fx[] = { 0, -2, -1, 1, 2, 2, 1, -1, -2 };
const int fy[] = { 0, 1, 2, 2, 1, -1, -2, -2, -1 };

long long f[40][40];
bool s[40][40];
int bx, by, mx, my;
int main() {
    cin >> bx >> by >> mx >> my;
    bx += 2, by += 2, mx += 2, my += 2;
    f[2][1] = 1;
    s[mx][my] = 1;

    for (int i = 1; i <= 8; i++) {
        s[mx + fx[i]][my + fy[i]] = 1;
    }
    for (int i = 2; i <= bx; i++) {
        for (int j = 2; j <= by; j++) {
            if (s[i][j]) {
                continue;
            }
            f[i][j] = f[i - 1][j] + f[i][j - 1];
        }
    }

    cout << f[bx][by] << endl;

    return 0;
}

// 2.https://www.luogu.com.cn/problem/P1003
const int MAXN = 1e5 + 5;
int a[MAXN], b[MAXN], g[MAXN], k[MAXN];

int main() {
    int n, x, y;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> g[i] >> k[i];
    }
    cin >> x >> y;

    int ans = -1;
    for (int i = 0; i < n; i++) {
        if (x >= a[i] && y >= b[i] && x <= a[i] + g[i] && y <= b[i] + k[i]) {
            ans = i + 1;
        }
    }

    cout << ans << endl;

    return 0;
}

// 3.https://www.luogu.com.cn/problem/P1007
int a[5011], l, n, maxn = 0, minn = 0;
int main() {
    cin >> l >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];


        // 第i个士兵有两种撤离的方法，他们需要的时间分别为l+1-a[i]和a[i]
        maxn = max(maxn, max(l + 1 - a[i], a[i])); // 最大值：最靠近端点两个人各自向对方走, 时间较长的那个人的时间
        minn = max(minn, min(l + 1 - a[i], a[i])); // 最小值：所有人中走完桥最小值中的最大值
    }
    cout << minn << " " << maxn;
}

// 4.https://www.luogu.com.cn/problem/P1008
int main() {
    for (int i = 123; i <= 333; i++) {
        int a[10] = { 0 }, b[10] = { 0 }, c[10] = { 0 };

        a[1] = i / 100;
        a[2] = i % 100 / 10;
        a[3] = i % 100 % 10;

        b[1] = 2 * i / 100;
        b[2] = 2 * i % 100 / 10;
        b[3] = 2 * i % 100 % 10;

        c[1] = 3 * i / 100;
        c[2] = 3 * i % 100 / 10;
        c[3] = 3 * i % 100 % 10;

        if (a[1] * a[2] * a[3] * b[1] * b[2] * b[3] * c[1] * c[2] * c[3] == 362880 && a[1] + a[2] + a[3] + b[1] + b[2] + b[3] + c[1] + c[2] + c[3] == 45) {
            cout << i << ' ' << i * 2 << ' ' << i * 3 << endl;
        }
    }

    return 0;
}

// 5.https://www.luogu.com.cn/problem/P1010
void fff(int n) {
    for (int i = 14; i >= 0; i--) {
        if (pow(2, i) <= n) {
            if (i == 1) {
                cout << "2";
            }
            else if (i == 0) {
                cout << "2(0)";
            }
            else {
                cout << "2(";
                fff(i);
                cout << ")";
            }

            n -= pow(2, i);

            if (n != 0) {
                cout << "+";
            }
        }
    }
}

int num;
int main() {
    cin >> num;
    fff(num);

    return 0;
}

// 6.https://www.luogu.com.cn/problem/P1011
int main() {
    int a, n, m, x, b, f[20];
    cin >> a >> n >> m >> x;
    f[1] = 1;

    for (int _ = 2; _ <= n - 1; f[_] = f[_ - 1] + f[_ - 2], _++) {
        ;
    }
    b = (m - (f[n - 3] + 1) * a) / (f[n - 2] - 1);

    cout << (f[x - 2] + 1) * a + (f[x - 1] - 1) * b << endl;

    return 0;
}

// 7.https://www.luogu.com.cn/problem/P1012
bool cmp(string a, string b) {
    return a + b > b + a;
}

int main() {
    int n;
    cin >> n;
    string a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n, cmp);

    string ans;
    for (int i = 0; i < n; i++) {
        ans += a[i];
    }

    cout << ans << endl;

    return 0;
}

// 8.https://www.luogu.com.cn/problem/P1014
int main() {
    int n, i = 0, j = 0; //前i条斜线一共j个数
    scanf("%d", &n);
    while (n > j) { //找到最小的i使得j>=n
        i++;
        j += i;
    }
    if (i % 2 == 1)
        printf("%d/%d", j - n + 1, i + n - j);//i的奇偶决定着斜线上数的顺序,n是第i条斜线上倒数第j-n+1个数
    else
        printf("%d/%d", i + n - j, j - n + 1);//若i是偶数，第i条斜线上倒数第i个元素是(i+1-i)/i
    return 0;
}
