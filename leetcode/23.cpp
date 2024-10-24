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
        int cur = 10000;
        list<ListNode*> nodeList;
        ListNode ans;
        ListNode* curNode = &ans;
        for (int i = 0, len = lists.size(); i < len; ++i) {
            if (lists[i] != nullptr) {
                nodeList.push_back(lists[i]);
                if (lists[i]->val < cur) cur = lists[i]->val;
            }
        }
        while (!nodeList.empty()) {
            int next = 10000;
            for (auto it = nodeList.begin(); it != nodeList.end();) {
                ListNode* search = (*it);
                while (search != nullptr) {
                    if (search->val == cur) {
                        curNode->next = search;
                        curNode = search;
                        search = search->next;
                    }
                    else if (search->val > cur) {
                        if (search->val < next) next = search->val;
                        break;
                    }
                }
                if (search == nullptr) it = nodeList.erase(it);
                else {
                    *it = search;
                    ++it;
                }
            }
            cur = next;
        }
        return ans.next;
    }
};