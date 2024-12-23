class Solution {
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int total = 0;
        while (!q.empty()) {
            int size = q.size();
            vector<int> origin(size);
            vector<int> sorted(size);
            unordered_map<int, int> idxmap;
            for (int i = 0; i < size; ++i) {
                TreeNode* v = q.front();
                q.pop();
                origin[i] = v->val;
                sorted[i] = v->val;
                idxmap[v->val] = i;
                if (v->left != nullptr) q.push(v->left);
                if (v->right != nullptr) q.push(v->right);
            }
            sort(sorted.begin(), sorted.end());
            for (int i = 0; i < size; ++i) {
                if (sorted[i] != origin[i]) {
                    ++total;
                    int swapidx = idxmap[sorted[i]];
                    idxmap[origin[i]] = swapidx;
                    swap(origin[i], origin[swapidx]);
                }
            }
        }
        return total;
    }
};