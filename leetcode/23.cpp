/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [](ListNode* one, ListNode* two){
            return one->val > two->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq;
        ListNode ans;
        ListNode* curNode = &ans;
        for (int i = 0, len = lists.size(); i < len; ++i) {
            if (lists[i] != nullptr) {
                pq.push(lists[i]);
            }
        }

        while (!pq.empty()) {
            ListNode* cur = pq.top();
            pq.pop();
            int val = cur->val;
            while (cur != nullptr && cur->val == val) {
                curNode->next = cur;
                curNode = cur;
                cur = cur->next;
            }
            if (cur != nullptr) pq.push(cur);
        }
        return ans.next;
    }
};