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
            //graph.size() - 1���ǽڵ�n - 1
            //path�����һ��Ԫ�ص���graph.size() - 1ʱ,��������result
            result.push_back(path);
            //������һ���ڵ�
            return;
        }

        //indexΪ��ǰ�ڵ�
        for (int i = 0; i < graph[index].size(); i++) {
            //����һ���ڵ���ӵ�path��
            path.push_back(graph[index][i]);
            //�ݹ�xQ
            dfs(graph, graph[index][i]);
            //�ݹ������graph[index][i]ɾ��,ѭ������һ���ڵ�����ѭ��
            path.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        result.clear();
        path.clear();
        //�ӽڵ�0��ʼ
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

    //ǰ�����:�� ������ ������
    void dfs(TreeNode* root) {
        //���ڵ�Ϊ��
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

    //�������:������ �� ������
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

    //�������:������ ������ ��
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