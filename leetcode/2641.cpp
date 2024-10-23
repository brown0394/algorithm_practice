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
 using pairNode = pair<TreeNode*, TreeNode*>;
class Solution {
    int pushQ(queue<pairNode>& q, TreeNode* node) {
        int sum = 0;
        if (node->left != nullptr) sum += node->left->val;
        if (node->right != nullptr) sum += node->right->val;
        q.push({node->left, node->right});
        return sum;
    }
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<pairNode> q;
        q.push({root, nullptr});
        int sum = root->val;
        while (!q.empty()) {
            int len = q.size();
            int nextSum = 0;
            for (int i = 0; i < len; ++i) {
                pairNode& node = q.front();
                int cur = 0;
                if (node.first != nullptr) {
                    cur = node.first->val;
                    nextSum += pushQ(q, node.first);
                    if (node.second != nullptr) {
                        cur += node.second->val;
                        node.second->val = sum - cur;
                        nextSum += pushQ(q, node.second);
                    }
                    node.first->val = sum - cur;
                }
                else if (node.second != nullptr) {
                    cur = node.second->val;
                    node.second->val = sum - cur;
                    nextSum += pushQ(q, node.second);
                }
                q.pop();
            }
            sum = nextSum;
        }
        return root;
    }
};