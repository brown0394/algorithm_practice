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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* ans = new ListNode();
        ListNode* cur = ans;
        while (true) {
            int calc = l1->val + l2->val + carry;
            cur->val = calc % 10;
            carry = calc / 10;
            l1 = l1->next;
            l2 = l2->next;
            if (l1 == nullptr) {
                cur->next = l2;
                break;
            }
            else if (l2 == nullptr) {
                cur->next = l1;
                break;
            }
            cur->next = new ListNode();
            cur = cur->next;
        }
        while (carry && cur->next != nullptr) {
            cur = cur->next;
            int calc = cur->val + 1;
            cur->val = calc % 10;
            carry = calc / 10;
        }
        if (carry) {
            cur->next = new ListNode(1);
        }
        return ans;
    }
};