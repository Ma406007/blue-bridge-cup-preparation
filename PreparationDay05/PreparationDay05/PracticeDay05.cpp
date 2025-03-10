//第十五届蓝桥杯省赛(软件赛) C/C++ 大学B组

//1.握手 100
//#include<iostream>
//using namespace std;
//int main() {
//	cout << 50 * 49 / 2 - 7 * 6 / 2 << endl;
//}

//2.小球反弹 100
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int main() {
//	int dx = 15, dy = 17;
//	int width = 343720 * 2, height = 233333 * 2;
//	for (int t = 1;; t++) {
//		if (dx * t % width == 0 && dy * t % height == 0) {
//			printf("%.2f", sqrt(pow(dx * t, 2) + pow(dy * t, 2)));
//			break;
//		}
//	}
//	return 0;
//}

//3.好数 100
//#include<iostream>
//using namespace std;
//int main() {
//	int n;
//	int ans = 0;
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		bool flag = true;
//		int tmp = i;
//
//		int count = 1;
//		while (tmp) {
//			int num = tmp % 10;
//			if (count % 2 == 1 && num % 2 != 1) {
//				flag = false;
//				break;
//			}
//			if (count % 2 == 0 && num % 2 != 0) {
//				flag = false;
//				break;
//			}
//			count++;
//			tmp /= 10;
//		}
//
//		if (flag) {
//			ans++;
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}

//4.R格式 50
//#include<iostream>
//#include<algorithm>
//using namespace std;
//int main() {
//	double d;
//	int n;
//	cin >> n >> d;
//	double ans = d * pow(2, n);
//	cout << round(ans) << endl;
//	return 0;
//}

//5.https://leetcode.cn/problems/permutations/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int>& nums, vector<bool>& used) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == true) {
                continue;
            }
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        result.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }
};

//6.https://leetcode.cn/problems/letter-combinations-of-a-phone-number/
//class Solution6 {
//private:
//    const string letterMap[10] = {
//        "",//0
//        "",//1
//        "abc",//2
//        "def",//3
//        "ghi",//4
//        "jkl",//5
//        "mno",//6
//        "pqrs",//7
//        "tuv",//8
//        "wxyz",//9
//    };
//
//public:
//    vector<string> result;
//    string path;
//
//    void backtracking(string digits, int index) {
//        if (index == digits.size()) {
//            result.push_back(path);
//            return;
//        }
//
//        int digit = digits[index] - '0';//将index指向的数字转为int
//        string letters = letterMap[digit];//取出数字对应的字符集
//        for (int i = 0; i < letters.size(); i++) {
//            path.push_back(letters[i]);
//            backtracking(digits, index + 1);
//            path.pop_back();
//        }
//    }
//
//    vector<string> letterCombinations(string digits) {
//        result.clear();
//        path.clear();
//        if (digits.size() == 0) {
//            return result;
//        }
//        backtracking(digits, 0);
//        return result;
//    }
//};