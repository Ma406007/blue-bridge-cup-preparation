#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//1.KMP算法模板
class KMP_Search {
public:
    int kmp_search(string str, string pattern) {
        int n = str.size(), m = pattern.size();
        if (m == 0) {
            return 0;
        }
        //设置哨兵
        str.insert(str.begin(), ' ');
        pattern.insert(pattern.begin(), ' ');

        vector<int> next(m + 1);
        //预处理next数组
        for (int i = 2, j = 0; i <= m; i++) {
            while (j > 0 && pattern[i] != pattern[j + 1]) {
                j = next[j];
            }
            if (pattern[i] == pattern[j + 1]) {
                j++;
            }
            next[i] = j;
        }
        //匹配过程
        for (int i = 1, j = 0; i <= n; i++) {
            while (j > 0 && str[i] != pattern[j + 1]) {
                j = next[j];
            }
            if (str[i] == pattern[j + 1]) {
                j++;
            }
            if (j == m) {
                return i - m;
            }
        }
        return -1;
    }
};
int main() {
	KMP_Search kmp;
	cout << kmp.kmp_search("abbcfdddbddcaddebc", "ABCABCD") << endl;
	cout << kmp.kmp_search("abbcfdddbddcaddebc", "bcf") << endl;
	cout << kmp.kmp_search("aaaaa", "bba") << endl;
	cout << kmp.kmp_search("mississippi", "issip") << endl;
	cout << kmp.kmp_search("ababbbbaaabbbaaa", "bbbb") << endl;
	return 0;
}

//2.https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/
class Solution02 {
public:
    int strStr(string str, string pattern) {
        int n = str.size(), m = pattern.size();
        if (m == 0) {
            return 0;
        }
        //设置哨兵
        str.insert(str.begin(), ' ');
        pattern.insert(pattern.begin(), ' ');

        vector<int> next(m + 1);
        //预处理next数组
        for (int i = 2, j = 0; i <= m; i++) {
            while (j > 0 && pattern[i] != pattern[j + 1]) {
                j = next[j];
            }
            if (pattern[i] == pattern[j + 1]) {
                j++;
            }
            next[i] = j;
        }
        //匹配过程
        for (int i = 1, j = 0; i <= n; i++) {
            while (j > 0 && str[i] != pattern[j + 1]) {
                j = next[j];
            }
            if (str[i] == pattern[j + 1]) {
                j++;
            }
            if (j == m) {
                return i - m;
            }
        }
        return -1;
    }
};