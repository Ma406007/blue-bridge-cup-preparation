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

//2.KMP算法模板
//构建Next数组(核心中的核心)
vector<int> buildNext(const string& pattern) {
    int n = pattern.size();
    vector<int> next(n, 0);
    next[0] = -1;//起始标记

    int i = 0;//主指针(后缀末尾)
    int j = -1;//前缀末尾(同时也是最长公共前后缀长度)

    /*
    * 生成偏移量:
    * 将next数组的第一个元素初始化为0,随后next数组后面的每一个元素都与模式串p的每一个元素都有一个偏移量,这个偏移量的值为1,例如:
    *   第一个元素(index==0)没有最长公共前后缀长度,故其对应的next数组的元素应为next[0+1]=next[1]=0
    *   从第二个元素开始往后(index>=1)都可能有最长公共前后缀长度,故其对应的next数组的元素应为next[index+1]=j
    * 
    * 为什么要有这种偏移量?
    *   当文本串与模式串失配时,假设对应模式串pattern的失配下标为index,由上述偏移量可以得到其对应的next数组元素next[index]应为前一个下标元素的最长公共前后缀长度
    *   由next[index]就可以得到我们应该将指针j回退next[index]个下标(因为前next[index]个元素是重复的,可以直接跳过)
    */

    //注意只遍历到倒数第二个字符
    while (i < n - 1) {
        //情况1:前后缀匹配成功
        if (j == -1 || pattern[i] == pattern[j]) {
            i++;
            j++;
            next[i] = j;//记录最长公共前后缀长度
        }
        //情况2:匹配失败,向前回溯
        else {
            j = next[j];//关键操作:利用已计算的next值回退
        }
    }
    return next;
}
//KMP主算法
vector<int> kmpSearch(const string& text, const string& pattern) {
    vector<int> matches;//存储所有匹配的起始位置
    int n = text.size(), m = pattern.size();
    //模式串为空或者模式串长度大于主串则没有匹配位置
    if (m == 0 || n < m) {
        return matches;
    }

    //构造next数组
    vector<int> next = buildNext(pattern);
    int i = 0;//text指针
    int j = 0;//pattern指针

    while (i < n) {
        //情况1:字符匹配成功
        if (j == -1 || text[i] == pattern[j]) {
            i++;
            j++;
            //找到完整匹配
            //如果指针j移动到了模式串pattern的末尾,说明匹配成功,记录下标并且将指针j回退(或将模式串向右移动)
            if (j == m) {
                matches.emplace_back(i - j);//记录起始位置
                j = next[j - 1];//继续寻找其他匹配
            }
        }
        //情况2:字符不匹配
        else {
            j = next[j];//模式串向右滑动
        }
    }
    return matches;
}
int main() {

    string text = "ABABABABC";
    string pattern = "ABABC";

    cout << "Next数组: ";
    vector<int> next = buildNext(pattern);
    for (int num : next) cout << num << " ";
    cout << endl;

    vector<int> positions = kmpSearch(text, pattern);
    if (!positions.empty()) {
        cout << "匹配位置：";
        for (int pos : positions) cout << pos << " ";
    }
    else {
        cout << "未找到匹配";
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