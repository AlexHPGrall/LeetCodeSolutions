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
    ListNode* deleteMiddle(ListNode* head) {
        int n=0;
        ListNode* curr=head;
        while(curr)
        {
            ++n;
            curr=curr->next;
        }
        int m=n/2;
        n=0;
        curr=head;
        if(m==0)
            return nullptr;
        while(curr)
        {
            ++n;
            if(n==m)
            {curr->next=curr->next->next;break;}
            curr=curr->next;
            
        }
        return head;
    }
};