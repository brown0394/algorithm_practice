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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head;
        for (int i = 0; i < n; ++i) {
            cur = cur->next;
        }
        ListNode* target = head;
        ListNode* last = head;
        while (cur != nullptr) {
            cur = cur->next;
            last = target;
            target = target->next;
        }
        if (last == head && target == head) return head->next;
        last->next = target->next;
        return head;
    }
};