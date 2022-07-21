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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* curr, *next, *prev;
        curr=head;
        next=curr;
        
        for(int i=1;i<left;++i)
        {
            prev=next;
            next=next->next;
        }
        ListNode *start=prev;

        for(int i=left;i<=right;++i)
        {
            curr=next;
            next=curr->next;
            curr->next=prev;
            prev=curr;
            
        }
        
        if(left==1)
        {
            head->next=next;
            return prev;
        }
        else
        {
            start->next->next=next;
            start->next=prev;
        }
        
        return head;
    }
};