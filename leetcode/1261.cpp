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
class FindElements {
    unordered_set<int> numSet;
    void traverse(TreeNode* cur, int val)
    {
        if (cur == nullptr)
            return;
        numSet.insert(val);
        val <<= 1;
        traverse(cur->left, val+1);
        traverse(cur->right, val+2);
    }
public:
    FindElements(TreeNode* root) {
        if (root == nullptr)
            return;
        numSet.insert(0);
        traverse(root->left, 1);
        traverse(root->right, 2);
    }
    
    bool find(int target) {
        return numSet.find(target) != numSet.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */