class Solution {
public:
    int minimumOperations(TreeNode* root) {
        auto comp = [](TreeNode* one, TreeNode* two)->bool {
            return one->val > two->val;
            };
        vector<TreeNode*> pq;
        vector<TreeNode*> pq2;
        vector<TreeNode*>* curpq = &pq;
        vector<TreeNode*>* nextpq = &pq2;
        deque<TreeNode*> dq;
        dq.push_back(root);
        curpq->push_back(root);
        int total = 0;
        while (!dq.empty()) {
            int size = dq.size();
            for (int i = 0; i < size; ++i) {
                pop_heap(curpq->begin(), curpq->end(), comp);
                TreeNode* cur = curpq->back();
                TreeNode* front = dq.front();
                dq.pop_front();
                if (cur->val != front->val) {
                    swap(cur->val, front->val);
                    make_heap(curpq->begin(), curpq->end(), comp);
                    pop_heap(curpq->begin(), curpq->end(), comp);
                    ++total;
                }
                curpq->pop_back();
                if (front->left != nullptr) {
                    dq.push_back(front->left);
                    nextpq->push_back(front->left);
                    push_heap(nextpq->begin(), nextpq->end(), comp);
                }
                if (front->right != nullptr) {
                    dq.push_back(front->right);
                    nextpq->push_back(front->right);
                    push_heap(nextpq->begin(), nextpq->end(), comp);
                }
            }
            swap(curpq, nextpq);
        }
        return total;
    }
};