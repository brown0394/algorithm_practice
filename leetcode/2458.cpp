/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<vector<pair<int, int>>> levelNodes;
    vector<int> levelIdx;
    int dfs(TreeNode* cur, int level) {
        if (levelNodes.size() <= level) levelNodes.resize(level + 1);
        if (levelIdx.size() <= cur->val) levelIdx.resize(cur->val + 1);
        levelIdx[cur->val] = level;
        int deepest = level;
        if (cur->left != nullptr) {
            deepest = dfs(cur->left, level + 1);
        }
        if (cur->right != nullptr) {
            int ret = dfs(cur->right, level + 1);
            if (ret > deepest) deepest = ret;
        }
        levelNodes[level].push_back({cur->val, deepest});
        return deepest;
    }
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        dfs(root, 0);
        vector<int> ans(queries.size());
        for (int i = 0, len = queries.size(); i < len; ++i) {
            int maxVal = levelIdx[queries[i]] - 1;
            for (pair<int, int>& val : levelNodes[levelIdx[queries[i]]]) {
                if (val.first != queries[i] && val.second > maxVal) maxVal = val.second;
            }
            ans[i] = maxVal;
        }
        return ans;
    }
};