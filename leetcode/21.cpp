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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* cur;
        if (list1 == nullptr) {
            if (list2 == nullptr) return nullptr;
            return list2;
        }
        if (list2 == nullptr) return list1;
        ListNode ans;
        cur = &ans;
        while (true) {
            if (list1->val < list2->val) {
                cur->next = list1;
                list1 = list1->next;
                if (list1 == nullptr) {
                    cur->next->next = list2;
                    break;
                }
            }
            else {
                cur->next = list2;
                list2 = list2->next;
                if (list2 == nullptr) {
                    cur->next->next = list1;
                    break;
                }
            }
            cur = cur->next;
        }
        return ans.next;
    }
};