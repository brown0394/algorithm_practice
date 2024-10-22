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
    struct node {
        TreeNode* tnode;
        int level;
    };
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> sums;
        queue<node> q;
        int size = 0;
        int level = 1;
        q.push({root, level});
        while (!q.empty()) {
            node& cur = q.front();
            if (size < cur.level) {
                sums.push_back(cur.tnode->val);
                ++size;
            }
            else sums[cur.level - 1] += cur.tnode->val;
            if (cur.tnode->left != nullptr) q.push({cur.tnode->left, cur.level + 1});
            if (cur.tnode->right != nullptr) q.push({cur.tnode->right, cur.level + 1});
            q.pop();
        }
        if (size < k) return -1;
        sort(sums.begin(), sums.end(), greater<long long>());
        return sums[k-1];
    }
};