#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//1.https://leetcode.cn/problems/n-ary-tree-preorder-traversal/
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
class Solution1 {
public:
    vector<int> treeNode;

    void dfs(Node* root) {
        //节点为nullptr或节点没有子节点
        if (root == nullptr || root->children.size() == 0) {
            return;
        }

        for (int i = 0; i < root->children.size(); i++) {
            treeNode.push_back(root->children[i]->val);
            dfs(root->children[i]);
        }
    }

    vector<int> preorder(Node* root) {
        treeNode.clear();
        if (root == nullptr) {
            return treeNode;
        }
        treeNode.push_back(root->val);
        dfs(root);
        return treeNode;
    }
};

//2.https://leetcode.cn/problems/n-ary-tree-postorder-traversal/
class Solution2 {
public:
    vector<int> treeNode;

    void dfs(Node* root) {
        if (root == nullptr) {
            return;
        }

        for (int i = 0; i < root->children.size(); i++) {
            dfs(root->children[i]);
            treeNode.push_back(root->children[i]->val);
        }
    }

    vector<int> postorder(Node* root) {
        treeNode.clear();
        if (root == nullptr) {
            return treeNode;
        }
        dfs(root);
        treeNode.push_back(root->val);
        return treeNode;
    }
};

//3.https://leetcode.cn/problems/minimum-depth-of-binary-tree/
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution3 {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }

        int min_depth = INT_MAX;
        if (root->left != nullptr) {
            min_depth = min(minDepth(root->left), min_depth);
        }
        if (root->right != nullptr) {
            min_depth = min(minDepth(root->right), min_depth);
        }

        return min_depth + 1;
    }
};

//4.https://leetcode.cn/problems/binary-tree-right-side-view/
class Solution4 {
public:
    vector<int> res;

    void dfs(TreeNode* node, int u) {
        if (u == res.size()) {
            res.push_back(node->val);
        }

        if (node->right) {
            dfs(node->right, u + 1);
        }
        if (node->left) {
            dfs(node->left, u + 1);
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        res.clear();
        if (root) {
            dfs(root, 0);
        }
        return res;
    }
};

//5.https://leetcode.cn/problems/same-tree/
class Solution5 {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }
        else if (p == nullptr || q == nullptr) {
            return false;
        }
        else if (p->val != q->val) {
            return false;
        }
        else {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }
};

//6.https://leetcode.cn/problems/subtree-of-another-tree/
class Solution6 {
public:
    bool check(TreeNode* o, TreeNode* t) {
        if (!o && !t) {
            return true;
        }
        if ((o && !t) || (!o && t) || (o->val != t->val)) {
            return false;
        }
        return check(o->left, t->left) && check(o->right, t->right);
    }

    bool dfs(TreeNode* o, TreeNode* t) {
        if (!o) {
            return false;
        }
        return check(o, t) || dfs(o->left, t) || dfs(o->right, t);
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        return dfs(s, t);
    }
};

//7.https://www.lanqiao.cn/problems/782/learning/?page=1&first_category_id=1&tags=%E5%86%92%E6%B3%A1%E6%8E%92%E5%BA%8F,%E6%8E%92%E5%BA%8F,%E5%BD%92%E5%B9%B6%E6%8E%92%E5%BA%8F,%E5%BF%AB%E9%80%9F%E6%8E%92%E5%BA%8F,%E6%A1%B6%E6%8E%92%E5%BA%8F&tag_relation=union&problem_id=782
//bool rule(string a, string b) {
//    return a + b > b + a;
//}
//int main() {
//    string array[20]; int n;
//    cin >> n;
//    for (int i = 0; i < n; i++)
//        cin >> array[i];
//    sort(array, array + n, rule);
//    for (int i = 0; i < n; i++)
//        cout << array[i];
//    return 0;
//}

//8.https://www.lanqiao.cn/problems/1265/learning/?page=1&first_category_id=1&tags=%E5%86%92%E6%B3%A1%E6%8E%92%E5%BA%8F,%E6%8E%92%E5%BA%8F,%E5%BD%92%E5%B9%B6%E6%8E%92%E5%BA%8F,%E5%BF%AB%E9%80%9F%E6%8E%92%E5%BA%8F,%E6%A1%B6%E6%8E%92%E5%BA%8F&tag_relation=union&problem_id=1265
//int main() {
//    int n;
//    cin >> n;
//    vector<int> arr;
//    for (int i = 0; i < n; i++) {
//        int num;
//        cin >> num;
//        arr.push_back(num);
//    }
//    sort(arr.begin(), arr.end());
//    for (int i = 0; i < n; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//    for (int i = n - 1; i >= 0; i--) {
//        cout << arr[i] << " ";
//    }
//    return 0;
//}

//9.https://www.lanqiao.cn/problems/17022/learning/?page=1&first_category_id=1&tags=%E5%86%92%E6%B3%A1%E6%8E%92%E5%BA%8F,%E6%8E%92%E5%BA%8F,%E5%BD%92%E5%B9%B6%E6%8E%92%E5%BA%8F,%E5%BF%AB%E9%80%9F%E6%8E%92%E5%BA%8F,%E6%A1%B6%E6%8E%92%E5%BA%8F&tag_relation=union&problem_id=17022
//int main() {
//    vector<int> jishu;
//    vector<int> oushu;
//    int n;
//    cin >> n;
//    for (int i = 0; i < n; i++) {
//        int num;
//        cin >> num;
//        if (num % 2 == 0) {
//            oushu.push_back(num);
//        }
//        else {
//            jishu.push_back(num);
//        }
//    }
//    sort(jishu.begin(), jishu.end());
//    sort(oushu.begin(), oushu.end());
//    for (int i = 0; i < jishu.size(); i++) {
//        cout << jishu[i] << " ";
//    }
//    for (int i = 0; i < oushu.size(); i++) {
//        cout << oushu[i] << " ";
//    }
//    return 0;
//}

//10.https://www.lanqiao.cn/problems/301/learning/?page=1&first_category_id=1&tags=%E5%86%92%E6%B3%A1%E6%8E%92%E5%BA%8F,%E6%8E%92%E5%BA%8F,%E5%BD%92%E5%B9%B6%E6%8E%92%E5%BA%8F,%E5%BF%AB%E9%80%9F%E6%8E%92%E5%BA%8F,%E6%A1%B6%E6%8E%92%E5%BA%8F&tag_relation=union&problem_id=301

//int a[105];
//int main() {
//    int n;
//    cin >> n;
//    for (int i = 1; i <= n; i++) {
//        cin >> a[i];
//    }
//    sort(a + 1, a + 1 + n);
//    for (int i = 1; i <= n; i++) {
//        cout << a[i] << " ";
//    }
//    return 0;
//}