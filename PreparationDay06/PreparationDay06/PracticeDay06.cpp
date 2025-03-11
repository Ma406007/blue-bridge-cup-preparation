#include<iostream>
#include<vector>
using namespace std;

//1.https://leetcode.cn/problems/all-paths-from-source-to-target/
class Solution1 {
public:
    vector<vector<int>> result;
    vector<int> path;

    void dfs(vector<vector<int>>& graph, int index) {
        if (index == graph.size() - 1) {
            //graph.size() - 1就是节点n - 1
            //path的最后一个元素等于graph.size() - 1时,将其添入result
            result.push_back(path);
            //返回上一个节点
            return;
        }

        //index为当前节点
        for (int i = 0; i < graph[index].size(); i++) {
            //将下一个节点添加到path中
            path.push_back(graph[index][i]);
            //递归xQ
            dfs(graph, graph[index][i]);
            //递归结束后将graph[index][i]删除,循环至下一个节点或结束循环
            path.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        result.clear();
        path.clear();
        //从节点0开始
        path.push_back(0);
        dfs(graph, 0);
        return result;
    }
};

//2.https://leetcode.cn/problems/binary-tree-preorder-traversal/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution2 {
public:
    vector<int> Node;

    //前序遍历:根 左子树 右子树
    void dfs(TreeNode* root) {
        //根节点为空
        if (root == nullptr) {
            return;
        }
        Node.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        Node.clear();
        dfs(root);
        return Node;
    }
};

//3.https://leetcode.cn/problems/binary-tree-inorder-traversal/
class Solution3 {
public:
    vector<int> Node;

    //中序遍历:左子树 根 右子树
    void dfs(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        dfs(root->left);
        Node.push_back(root->val);
        dfs(root->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        Node.clear();
        dfs(root);
        return Node;
    }
};

//4.https://leetcode.cn/problems/binary-tree-postorder-traversal/
class Solution4 {
public:
    vector<int> Node;

    //后序遍历:左子树 右子树 根
    void dfs(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        dfs(root->left);
        dfs(root->right);
        Node.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        Node.clear();
        dfs(root);
        return Node;
    }
};