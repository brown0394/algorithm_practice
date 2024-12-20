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
    TreeNode* reverseOddLevels(TreeNode* root) {
        deque<TreeNode*> dq;
        dq.push_back(root);
        bool bReverse = false;
        while (!dq.empty()) {
            int size = dq.size();
            if (bReverse) {
                bReverse = false;
                int right = size - 1;
                int left = 0;
                while (left < right) {
                    swap(dq[left]->val, dq[right]->val);
                    ++left;
                    --right;
                }
            }
            else bReverse = true;
            for (int i = 0, size = dq.size(); i < size; ++i) {
                if (dq.front()->left == nullptr) {
                    dq.pop_front();
                    continue;
                }
                dq.push_back(dq.front()->left);
                dq.push_back(dq.front()->right);
                dq.pop_front();
            }
        }
        return root;
    }
};