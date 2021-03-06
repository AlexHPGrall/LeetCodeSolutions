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
    ListNode* sortList(ListNode* head) {
        vector<int> list;
        ListNode* curr=head;
        while(curr)
        {
            list.push_back(curr->val);
            curr=curr->next;
        }
        sort(list.begin(),list.end());
        int i=0;
        curr=head;
        while(curr)
        {
            curr->val=list[i++];
            curr=curr->next;
        }
        return head;
    }
};