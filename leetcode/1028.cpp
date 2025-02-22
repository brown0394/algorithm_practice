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
    stack<TreeNode*> parentStack;
    int lastDepth = 0;
    int depth = 0;
    int num = 0;
    void pushNode()
    {
        TreeNode* newT = new TreeNode(num);
        if (depth > lastDepth)
            parentStack.top()->left = newT;
        else if (depth == lastDepth)
        {
            parentStack.pop();
            parentStack.top()->right = newT;
        }
        else
        {
            for (int i = lastDepth - depth; i >= 0; --i)
            {
                parentStack.pop();
            }
            parentStack.top()->right = newT;
        }
        lastDepth = depth;
        parentStack.push(newT);
        num = 0;
        depth = 1;
    }
public:
    TreeNode* recoverFromPreorder(string traversal) {
        int size = traversal.size();
        if (size == 0)
            return nullptr;
        int i = 0;
        while (i < size && traversal[i] != '-')
        {
            num = (num * 10) + (traversal[i] - '0');
            ++i;
        }
        TreeNode* root = new TreeNode(num);
        parentStack.push(root);
        num = 0;
        for (; i < size; ++i)
        {
            if (traversal[i] != '-')
            {
                num = (num * 10) + (traversal[i] - '0');
                continue;
            }
            
            if (num == 0)
            {
                ++depth;
                continue;
            }

            pushNode();
        }
        if (depth > 0)
            pushNode();
        return root;
    }
};