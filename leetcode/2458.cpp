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
    int maxLevel;
    int maxAfterPruning[100005];
    void lfdfs(TreeNode* cur, int level) {
        if (cur == nullptr) return;
        maxAfterPruning[cur->val] = max(maxLevel, level - 1);
        maxLevel = max(maxLevel, level);
        lfdfs(cur->left, level + 1);
        lfdfs(cur->right, level + 1);
    }
    void rfdfs(TreeNode* cur, int level) {
        if (cur == nullptr) return;
        maxAfterPruning[cur->val] = max(maxLevel, maxAfterPruning[cur->val]);
        maxLevel = max(maxLevel, level);
        rfdfs(cur->right, level + 1);
        rfdfs(cur->left, level + 1);
    }
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        maxLevel = 0;
        lfdfs(root, 0);
        maxLevel = 0;
        rfdfs(root, 0);
        vector<int> ans(queries.size());
        for (int i = 0, len = queries.size(); i < len; ++i) {
            ans[i] = maxAfterPruning[queries[i]];
        }
        return ans;
    }
};