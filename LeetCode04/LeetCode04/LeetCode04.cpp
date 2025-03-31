#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//1.https://leetcode.cn/problems/find-if-path-exists-in-graph/
class Solution01 {
public:
    bool dfs(int source, int destination, vector<vector<int>>& adj, vector<bool>& visited) {
        if (source == destination) {
            return true;
        }
        visited[source] = true;
        for (int next : adj[source]) {
            if (!visited[next] && dfs(next, destination, adj, visited)) {
                return true;
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            int x = edge[0], y = edge[1];
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        vector<bool> visited(n, false);
        return dfs(source, destination, adj, visited);
    }
};

//2.https://leetcode.cn/problems/range-sum-query-immutable/
class NumArray {
public:
    vector<int> sums;

    NumArray(vector<int>& nums) {
        int n = nums.size();
        sums.resize(n + 1);
        for (int i = 0; i < n; i++) {
            sums[i + 1] = sums[i] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        return sums[j + 1] - sums[i];
    }
};

//3.https://leetcode.cn/problems/sum-of-variable-length-subarrays/
class Solution03 {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size();

        // 预处理前缀和
        int f[n + 1];
        f[0] = 0;
        for (int i = 1; i <= n; i++) f[i] = f[i - 1] + nums[i - 1];

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int l = max(0, i - nums[i]);
            // 前缀和计算子数组之和
            ans += f[i + 1] - f[l];
        }
        return ans;
    }
};
