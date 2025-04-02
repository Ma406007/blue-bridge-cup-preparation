#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_set>
using namespace std;

//1.https://leetcode.cn/problems/maximum-value-of-an-ordered-triplet-i/?envType=daily-question&envId=2025-04-02
class Solution01_1 {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    res = max(res, (long long)(nums[i] - nums[j]) * nums[k]);
                }
            }
        }
        return res;
    }
};

class Solution01_2 {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for (int k = 2; k < n; k++) {
            int m = nums[0];
            for (int j = 1; j < k; j++) {
                ans = max(ans, (long long)(m - nums[j]) * nums[k]);
                m = max(m, nums[j]);
            }
        }
        return ans;
    }
};

class Solution01_3 {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftMax(n, 0), rightMax(n, 0);
        for (int i = 1; i < n; i++) {
            //leftMax维护[0, j)的最大值(前缀),易知leftMax前缀数组是递增的
            leftMax[i] = max(leftMax[i - 1], nums[i - 1]);
            //rightMax维护[j + 1, n)的最大值(前缀),易知rightMax前缀数组的递减的
            rightMax[n - i - 1] = max(rightMax[n - i], nums[n - i]);
        }

        long long ans = 0;
        for (int j = 1; j < n - 1; j++) {
            //固定j时,nums[i]和nums[k]分别取[0, j)和[j + 1, n)的最大值时,三元组的值最大
            ans = max(ans, (long long)(leftMax[j] - nums[j]) * rightMax[j]);
        }
        return ans;
    }
};

class Solution01_4 {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0, imax = 0, dmax = 0;
        for (int k = 0; k < n; k++) {
            ans = max(ans, (long long)dmax * nums[k]);
            dmax = max(dmax, (long long)(imax - nums[k]));
            imax = max(imax, (long long)nums[k]);
        }
        return ans;
    }
};

//2.https://leetcode.cn/problems/leaf-similar-trees/
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution02 {
public:
    vector<int> val1, val2;

    void dfs(TreeNode* root, vector<int>& arr) {
        if (root == nullptr) {
            return;
        }

        if (root->left == nullptr && root->right == nullptr) {
            arr.push_back(root->val);
        }
        dfs(root->left, arr);
        dfs(root->right, arr);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs(root1, val1);
        dfs(root2, val2);

        if (val1.size() != val2.size()) {
            return false;
        }
        for (int i = 0; i < val1.size(); i++) {
            if (val1[i] != val2[i]) {
                return false;
            }
        }
        return true;
    }
};

//3.https://leetcode.cn/problems/sZ59z6/
class Solution03 {
public:
    unordered_set<int> vals;

    void dfs(TreeNode* root, unordered_set<int>& sets) {
        if (root == nullptr) {
            return;
        }

        sets.insert(root->val);
        dfs(root->left, sets);
        dfs(root->right, sets);
    }

    int numColor(TreeNode* root) {
        dfs(root, vals);
        return vals.size();
    }
};

//4.https://leetcode.cn/problems/sum-of-left-leaves/
class Solution04 {
public:
    bool isLeafNode(TreeNode* node) {
        return !node->left && !node->right;
    }

    int dfs(TreeNode* node) {
        int ans = 0;

        if (node->left) {
            ans += isLeafNode(node->left) ? node->left->val : dfs(node->left);
        }
        if (node->right && !isLeafNode(node->right)) {
            ans += dfs(node->right);
        }

        return ans;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return root ? dfs(root) : 0;
    }
};

//5.https://leetcode.cn/problems/binary-tree-paths/
class Solution05 {
public:
    void dfs(TreeNode* node, string road, vector<string>& path) {
        if (node != nullptr) {
            road += to_string(node->val);
            if (node->left == nullptr && node->right == nullptr) {
                path.push_back(road);
                return;
            }
            else {
                road += "->";
                dfs(node->left, road, path);
                dfs(node->right, road, path);
            }
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> path;
        dfs(root, "", path);
        return path;
    }
};