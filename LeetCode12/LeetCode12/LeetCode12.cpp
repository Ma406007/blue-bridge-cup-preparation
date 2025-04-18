#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

//1.https://leetcode.cn/problems/count-number-of-bad-pairs/?envType=daily-question&envId=2025-04-18
class Solution01 {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long ans = 1LL * n * (n - 1) / 2;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            int t = i - nums[i];
            ans -= mp[t];
            mp[t]++;
        }

        return ans;
    }
};

//2.KMP�㷨ģ��
//����Next����(�����еĺ���)
vector<int> buildNext(const string& pattern) {
    int n = pattern.size();
    vector<int> next(n, 0);
    next[0] = -1;//��ʼ���

    int i = 0;//��ָ��(��׺ĩβ)
    int j = -1;//ǰ׺ĩβ(ͬʱҲ�������ǰ��׺����)

    /*
    * ����ƫ����:
    * ��next����ĵ�һ��Ԫ�س�ʼ��Ϊ0,���next��������ÿһ��Ԫ�ض���ģʽ��p��ÿһ��Ԫ�ض���һ��ƫ����,���ƫ������ֵΪ1,����:
    *   ��һ��Ԫ��(index==0)û�������ǰ��׺����,�����Ӧ��next�����Ԫ��ӦΪnext[0+1]=next[1]=0
    *   �ӵڶ���Ԫ�ؿ�ʼ����(index>=1)�������������ǰ��׺����,�����Ӧ��next�����Ԫ��ӦΪnext[index+1]=j
    * 
    * ΪʲôҪ������ƫ����?
    *   ���ı�����ģʽ��ʧ��ʱ,�����Ӧģʽ��pattern��ʧ���±�Ϊindex,������ƫ�������Եõ����Ӧ��next����Ԫ��next[index]ӦΪǰһ���±�Ԫ�ص������ǰ��׺����
    *   ��next[index]�Ϳ��Եõ�����Ӧ�ý�ָ��j����next[index]���±�(��Ϊǰnext[index]��Ԫ�����ظ���,����ֱ������)
    */

    //ע��ֻ�����������ڶ����ַ�
    while (i < n - 1) {
        //���1:ǰ��׺ƥ��ɹ�
        if (j == -1 || pattern[i] == pattern[j]) {
            i++;
            j++;
            next[i] = j;//��¼�����ǰ��׺����
        }
        //���2:ƥ��ʧ��,��ǰ����
        else {
            j = next[j];//�ؼ�����:�����Ѽ����nextֵ����
        }
    }
    return next;
}
//KMP���㷨
vector<int> kmpSearch(const string& text, const string& pattern) {
    vector<int> matches;//�洢����ƥ�����ʼλ��
    int n = text.size(), m = pattern.size();
    //ģʽ��Ϊ�ջ���ģʽ�����ȴ���������û��ƥ��λ��
    if (m == 0 || n < m) {
        return matches;
    }

    //����next����
    vector<int> next = buildNext(pattern);
    int i = 0;//textָ��
    int j = 0;//patternָ��

    while (i < n) {
        //���1:�ַ�ƥ��ɹ�
        if (j == -1 || text[i] == pattern[j]) {
            i++;
            j++;
            //�ҵ�����ƥ��
            //���ָ��j�ƶ�����ģʽ��pattern��ĩβ,˵��ƥ��ɹ�,��¼�±겢�ҽ�ָ��j����(��ģʽ�������ƶ�)
            if (j == m) {
                matches.emplace_back(i - j);//��¼��ʼλ��
                j = next[j - 1];//����Ѱ������ƥ��
            }
        }
        //���2:�ַ���ƥ��
        else {
            j = next[j];//ģʽ�����һ���
        }
    }
    return matches;
}
int main() {

    string text = "ABABABABC";
    string pattern = "ABABC";

    cout << "Next����: ";
    vector<int> next = buildNext(pattern);
    for (int num : next) cout << num << " ";
    cout << endl;

    vector<int> positions = kmpSearch(text, pattern);
    if (!positions.empty()) {
        cout << "ƥ��λ�ã�";
        for (int pos : positions) cout << pos << " ";
    }
    else {
        cout << "δ�ҵ�ƥ��";
    }
    return 0;
}

//3.https://leetcode.cn/problems/rotate-string/
class Solution03 {
public:
    vector<int> buildNext(string pattern) {
        int n = pattern.size();
        vector<int> next(n, 0);
        next[0] = -1;

        int i = 0;
        int j = -1;

        while (i < n - 1) {
            if (j == -1 || pattern[i] == pattern[j]) {
                i++;
                j++;
                next[i] = j;
            }
            else {
                j = next[j];
            }
        }
        return next;
    }

    vector<int> kmpSearch(string text, string pattern) {
        vector<int> matches;
        int n = text.size(), m = pattern.size();
        if (m == 0 || m > n) {
            return matches;
        }

        vector<int> next = buildNext(pattern);
        int i = 0;
        int j = 0;

        while (i < n) {
            if (j == -1 || text[i] == pattern[j]) {
                i++;
                j++;
                if (j == m) {
                    matches.emplace_back(i - j);
                    j = next[j - 1];
                }
            }
            else {
                j = next[j];
            }
        }
        return matches;
    }

    bool rotateString(string text, string pattern) {
        if (pattern.size() == 0 || text.size() < pattern.size() || text.size() > pattern.size()) {
            return false;
        }
        string total = text + text;
        vector<int> matches = kmpSearch(total, pattern);
        return matches.size() == 0 ? false : true;
    }
};

//4.https://leetcode.cn/problems/longest-happy-prefix/
class Solution04 {
public:
    vector<int> buildNext(string pattern) {
        int n = pattern.size();
        vector<int> next(n + 1, 0);
        next[0] = -1;

        int i = 0;
        int j = -1;

        while (i < n) {
            if (j == -1 || pattern[i] == pattern[j]) {
                i++;
                j++;
                next[i] = j;
            }
            else {
                j = next[j];
            }
        }
        return next;
    }

    string longestPrefix(string pattern) {
        vector<int> next = buildNext(pattern);
        int n = next[pattern.size()];
        return pattern.substr(0, n);
    }
};