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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        sort(nums.begin(), nums.end());
        
        ListNode tempHead;
        tempHead.next = head;
        ListNode* cur = &tempHead;
        vector<int>::iterator found;
        vector<int>::iterator endit = nums.end();
        while(cur->next != nullptr)
        {
            found = lower_bound(nums.begin(), endit, cur->next->val);
            if ( found != endit && *found == cur->next->val)
            {
                cur->next = cur->next->next;
                continue;
            }
            cur = cur->next;
        }

        return tempHead.next;
    }
};