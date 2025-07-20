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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return head;

        ListNode* next = head;

        while(next->next != nullptr)
        {
            if (next->next->val == next->val)
            {
                next->next = next->next->next;
                continue;
            }
            next = next->next;
        }
        return head;
    }
};