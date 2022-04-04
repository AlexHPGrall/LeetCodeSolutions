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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first, *sec;
        ListNode*curr=head;
        sec=head;
        for(int i=0; i<k-1;++i)
        {
            curr=curr->next;
        }
        first=curr;
        while(curr->next)
        {
            curr=curr->next;
            sec=sec->next;
        }
        swap(sec->val, first->val);
        return head;
    }
};