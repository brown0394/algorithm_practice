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
    void flushStack(stack<ListNode*>& stk, int count, ListNode*& last, ListNode*& cur) {
        last->next = stk.top();
        while (count > 1) {
            ListNode* temp = stk.top();
            stk.pop();
            temp->next = stk.top();
            --count;
        }
        stk.top()->next = cur;
        last = stk.top();
        stk.pop();
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) return head;
        stack<ListNode*> stk;
        ListNode* last;
        ListNode* cur = head;
        ListNode ans;
        int count = 0;
        while (cur != nullptr && count < k) {
            stk.push(cur);
            cur = cur->next;
            ++count;
        }
        last = &ans;
        flushStack(stk, count, last, cur);
        while (cur != nullptr) {
            count = 0;
            while (cur != nullptr && count < k) {
                stk.push(cur);
                cur = cur->next;
                ++count;
            }
            if (count == k) flushStack(stk, count, last, cur);
        }

        return ans.next;
    }
};