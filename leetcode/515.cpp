
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
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        if (root == nullptr) return {};
        q.push(root);
        vector<int> ans;
        while (!q.empty()) {
            int size = q.size();
            int maxV = q.front()->val;
            for (int i = 0; i < size; ++i) {
                TreeNode* t = q.front();
                q.pop();
                maxV = max(maxV, t->val);
                if (t->left != nullptr) q.push(t->left);
                if (t->right != nullptr) q.push(t->right);
            }
            ans.push_back(maxV);
        }
        return ans;
    }
};