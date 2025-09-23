// 1.https://www.lanqiao.cn/problems/3660/learning/?page=1&first_category_id=1&tags=%E5%86%92%E6%B3%A1%E6%8E%92%E5%BA%8F,%E6%8E%92%E5%BA%8F,%E5%BD%92%E5%B9%B6%E6%8E%92%E5%BA%8F,%E5%BF%AB%E9%80%9F%E6%8E%92%E5%BA%8F,%E6%A1%B6%E6%8E%92%E5%BA%8F&tag_relation=union&difficulty=30
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int main()
{
    vector<string> v;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        v.push_back(s);
    }
    sort(v.begin(), v.end());

    for (auto& c : v) {
        cout << c;
    }

    return 0;
}

// 2.https://www.lanqiao.cn/problems/3759/learning/?page=1&first_category_id=1&tags=%E5%86%92%E6%B3%A1%E6%8E%92%E5%BA%8F,%E6%8E%92%E5%BA%8F,%E5%BD%92%E5%B9%B6%E6%8E%92%E5%BA%8F,%E5%BF%AB%E9%80%9F%E6%8E%92%E5%BA%8F,%E6%A1%B6%E6%8E%92%E5%BA%8F&tag_relation=union&difficulty=30
#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;

unordered_map<string, int> cnt;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, l;
    cin >> n >> l;

    string s;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> s;
        sort(s.begin(), s.end());
        ans += (long long)cnt[s];
        cnt[s]++;

    }
    cout << ans;

    return 0;
}

// 3.