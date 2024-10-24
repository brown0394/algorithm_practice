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
    bool checkValid(TreeNode* node1, TreeNode* node2) {
        if (node1->left == nullptr && node1->right == nullptr) {
            if (node2->left == nullptr && node2->right == nullptr) return true;
            return false;
        }
        else if (node2->left == nullptr && node2->right == nullptr) return false;
        if (node1->left == nullptr) {
            if (node2->left == nullptr && node2->right->val == node1->right->val) {
                return checkValid(node1->right, node2->right);
            }
            else if (node2->right == nullptr && node2->left->val == node1->right->val) {
                return checkValid(node1->right, node2->left);
            }
            return false;
        }
        else if (node1->right == nullptr) {
            if (node2->left == nullptr && node2->right->val == node1->left->val) {
                return checkValid(node1->left, node2->right);
            }
            else if (node2->right == nullptr && node2->left->val == node1->left->val) {
                return checkValid(node1->left, node2->left);
            }
            return false; 
        }
        if (node2->left == nullptr || node2->right == nullptr) return false;
        if (node1->left->val == node2->left->val && node1->right->val == node2->right->val) {
            if (!checkValid(node1->left, node2->left)) return false;
            return checkValid(node1->right, node2->right);
        }
        else if (node1->left->val == node2->right->val && node1->right->val == node2->left->val) {
            if (!checkValid(node1->left, node2->right)) return false;
            return checkValid(node1->right, node2->left);
        }
        return false;
    }
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr) {
            if (root2 == nullptr) return true;
            return false;
        }
        if (root2 == nullptr) {
            return false;
        }
        if (root1->val != root2->val) return false;
        return checkValid(root1, root2);
    }
};