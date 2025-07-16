#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

// 1.https://www.lanqiao.cn/problems/17115/learning/?page=3&first_category_id=1&tags=%E5%8D%95%E4%BD%8D%E6%8D%A2%E7%AE%97,%E6%97%A5%E6%9C%9F%E9%97%AE%E9%A2%98,%E8%AF%AD%E6%B3%95&tag_relation=union
int dayOfMonth[12 + 1] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//������������ģ�û��һ���̶��ķ�Χ�����Լ�tot
int ans;
vector<int> count(string s, int tot)//�������
{
    vector<int>v;
    if (s == "*")//���ʽ������*
    {
        for (int i = 1; i <= tot; i++)//ȫ����
            v.push_back(i);
        return v;
    }
    //ʣ�������������һ��д�ˣ����ʽ����ֻ��һ���������
    int cur = 0;
    int lst = -1;
    for (auto c : s)
    {
        if (c == ',') {//Ҫôֻ�������֧
            if (cur <= tot)v.push_back(cur);
            cur = 0;
        }
        else if (c == '-')//Ҫôֻ�������֧
        {
            lst = cur;
            cur = 0;
        }
        else    cur = cur * 10 + (c - '0');//���õ�
    }
    //ĩβ�ַ�����
    if (lst != -1)//���ʽ������- 
        for (int i = lst; i <= min(cur, tot); i++)v.push_back(i);
    else//���ʽ����û�� -    ������ , 
        if (cur <= tot)v.push_back(cur);
    return v;
}
//���ŷָ� 
int main()
{
    string S, M, H, D, Mon; cin >> S >> M >> H >> D >> Mon;
    int pday = count(S, 60).size() * count(M, 60).size() * count(H, 24).size();//24Сʱ
    for (auto m : count(Mon, 12))
    {
        ans += pday * count(D, dayOfMonth[m]).size();
    }

    cout << ans << endl;
}

// 2.https://www.lanqiao.cn/problems/20321/learning/?page=86&first_category_id=1&tags=%E6%9E%9A%E4%B8%BE,%E6%A8%A1%E6%8B%9F,%E5%89%8D%E7%BC%80%E5%92%8C,%E5%B7%AE%E5%88%86,%E4%BA%8C%E5%88%86,%E8%BF%9B%E5%88%B6%E8%BD%AC%E6%8D%A2,%E8%B4%AA%E5%BF%83,%E4%BD%8D%E8%BF%90%E7%AE%97,%E5%8F%8C%E6%8C%87%E9%92%88&tag_relation=union2.
int main()
{
    int x;
    cin >> x;
    int i = 1;
    while (x > pow(2, i)) {
        i++;
    }
    int ans = pow(2, i) - x;
    cout << ans;
    return 0;
}

//3.https://www.lanqiao.cn/problems/20320/learning/?page=86&first_category_id=1&tags=%E6%9E%9A%E4%B8%BE,%E6%A8%A1%E6%8B%9F,%E5%89%8D%E7%BC%80%E5%92%8C,%E5%B7%AE%E5%88%86,%E4%BA%8C%E5%88%86,%E8%BF%9B%E5%88%B6%E8%BD%AC%E6%8D%A2,%E8%B4%AA%E5%BF%83,%E4%BD%8D%E8%BF%90%E7%AE%97,%E5%8F%8C%E6%8C%87%E9%92%88&tag_relation=union
int main(int argc, char* argv[])
{
    int n, i;
    scanf("%d", &n);
    int a[n], sum = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (i > 1 && a[i - 1] == 1 && a[i - 2] == 0 && a[i] == 0)
        {
            a[i] = 1;
            sum++;
        }
        else if (i > 0 && a[i] == 0 && a[i - 1] == 0)
        {
            a[i] = 1;
            sum++;
        }
    }
    printf("%d", sum);
    return 0;
}

//4.