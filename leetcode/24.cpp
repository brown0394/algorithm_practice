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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* cur = head->next;
        ListNode* last = head;
        ListNode* lastlast;
        if (cur != nullptr) {
            last->next = cur->next;
            lastlast = cur;
            head = lastlast;
            cur->next = last;
            cur = last->next;
            last = lastlast->next;
        }
        else return head;
        int moveCount = 1;
        while (cur != nullptr) {
            if (moveCount > 1) {
                moveCount = 0;
                lastlast->next = cur;
                last->next = cur->next;
                cur->next = last;
                swap(cur, last);
            }
            lastlast = last;
            last = cur;
            cur = cur->next;
            ++moveCount;
        }
        return head;
    }
};