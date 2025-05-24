#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
using namespace std;

//1.https://leetcode.cn/problems/find-words-containing-character/?envType=daily-question&envId=2025-05-24
class Solution01 {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;

        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                if (words[i][j] == x) {
                    ans.push_back(i);
                    break;
                }
            }
        }

        return ans;
    }
};

//2.https://leetcode.cn/problems/fair-candy-swap/
class Solution02 {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int sumB = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        int delta = (sumA - sumB) / 2;

        unordered_set<int> alice;
        for (auto& i : aliceSizes) {
            alice.insert(i);
        }

        vector<int> ans;
        for (auto& y : bobSizes) {
            int x = y + delta;
            if (alice.count(x)) {
                ans = vector<int>{ x, y };
                break;
            }
        }

        return ans;
    }
};

//3.https://leetcode.cn/problems/range-sum-of-bst/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution03 {
public:
    int sum = 0;

    void dfs(TreeNode* node, int low, int high) {
        if (node == nullptr) {
            return;
        }

        if (node->val >= low && node->val <= high) {
            sum += node->val;
        }
        dfs(node->left, low, high);
        dfs(node->right, low, high);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        dfs(root, low, high);

        return sum;
    }
};

//4.https://leetcode.cn/problems/xor-queries-of-a-subarray/
class Solution04 {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> xors(arr.size() + 1, 0);
        for (int i = 0; i < arr.size(); i++) {
            xors[i + 1] = xors[i] ^ arr[i];
        }

        vector<int> ans(queries.size(), 0);
        for (int i = 0; i < queries.size(); i++) {
            ans[i] = xors[queries[i][0]] ^ xors[queries[i][1] + 1];
        }

        return ans;
    }
};

//5.https://leetcode.cn/problems/calculate-score-after-performing-instructions/
class Solution05 {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        int n = instructions.size();
        long long score = 0;
        vector<bool> flags(n, false);

        int index = 0, value = 0;
        while (index >= 0 && index < n && flags[index] == false) {
            flags[index] = true;

            if (instructions[index] == "jump") {
                index += values[index];
            }
            else if (instructions[index] == "add") {
                score += values[index];
                index++;
            }
        }

        return score;
    }
};

//6.https://leetcode.cn/problems/o8SXZn/
class Solution06 {
public:
    int storeWater(vector<int>& bucket, vector<int>& vat) {
        int n = bucket.size();
        int maxk = *max_element(vat.begin(), vat.end());
        if (maxk == 0) {
            return 0;
        }
        int res = INT_MAX;
        for (int k = 1; k <= maxk && k < res; ++k) {
            int t = 0;
            for (int i = 0; i < bucket.size(); ++i) {
                t += max(0, (vat[i] + k - 1) / k - bucket[i]);
            }
            res = min(res, t + k);
        }
        return res;
    }
};