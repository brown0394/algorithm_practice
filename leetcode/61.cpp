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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr)
            return head;
        deque<ListNode*> dq;
        ListNode* cur = head;
        while (cur != nullptr)
        {
           dq.push_back(cur);
           cur = cur->next; 
        }
        k %= dq.size();
        for (int i = 0; i < k; ++i)
        {
            dq.back()->next = dq.front();
            dq.push_front(dq.back());
            dq.pop_back();
            dq.back()->next = nullptr;
        }
        return dq.front();
    }
};