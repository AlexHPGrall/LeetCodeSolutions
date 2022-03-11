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
    ListNode* rotateRight(ListNode* head, int k) {
        int n=0;
        ListNode *curr=head;
        ListNode *Prev;
        while(curr)
        {
            ++n;
            
            Prev=curr;
            curr=curr->next;
            
            
        }
        if(!n||n==1)
            return head;
        k=k%n;
        if(!k)
            return head;
        curr=head;
        Prev->next=curr;
        ListNode *res;
        for(int i=0;i<n-k-1;++i)
        {
            curr=curr->next;
        }
        res=curr->next;
        curr->next=nullptr;
        
        return res;
    }
};