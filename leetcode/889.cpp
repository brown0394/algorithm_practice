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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        if (preorder.empty() == true)
            return nullptr;
        int size = preorder.size();
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> parent;
        parent.push(root);
        int postIdx = 0;
        for (int i = 1; i < size; ++i)
        {
            TreeNode* cur = new TreeNode(preorder[i]);
            if (parent.top()->left == nullptr)
                parent.top()->left = cur;
            else
                parent.top()->right = cur;
            parent.push(cur);

            while(postIdx < size && postorder[postIdx] == parent.top()->val)
            {
                ++postIdx;
                parent.pop();
            }

        }
        return root;
    }
};