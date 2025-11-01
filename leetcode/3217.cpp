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
        
        ListNode* cur = head;
        ListNode* last = head;
        vector<int>::iterator found;
        vector<int>::iterator endit = nums.end();
        while( last != nullptr )
        {
            found = lower_bound(nums.begin(), endit, last->val);
            if ( found == endit || *found != last->val)
                break;
            last = last->next;
        }
        head = last;

        if (last == nullptr)
            return nullptr;
        cur = last->next;

        while(cur != nullptr)
        {
            found = lower_bound(nums.begin(), endit, cur->val);
            if ( found != endit && *found == cur->val)
            {
                last->next = cur->next;
                cur = cur->next;
                continue;
            }
            last = cur;
            cur = cur->next;
        }

        return head;
    }
};