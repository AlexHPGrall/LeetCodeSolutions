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
        ListNode *curr=head;
        ListNode *prev=NULL;
        if(head && head->next)
            head=head->next;
        while(curr && curr->next)
        {
            ListNode *nxt= curr->next;
            curr->next=curr->next->next;
            nxt->next=curr;
            if(prev)
                prev->next=nxt;
            prev=curr;
            curr=curr->next;
        }
        return head;
    }
};