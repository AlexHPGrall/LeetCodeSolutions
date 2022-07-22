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
    ListNode* partition(ListNode* head, int x) {
        if(!head)
            return head;
        ListNode *head2, *tail1, *tail2;
        ListNode *curr=head;
        if(head->val<x)
        {
            while(curr && curr->val<x)
            {
                tail1=curr;
                curr= curr->next;
            }
            if(!curr)
                return head;
            head2=curr;
            tail2=curr;
        }
        else
        {   head2=head;
            while(curr && curr->val>=x)
            {
                tail2=curr;
                curr= curr->next;
            }
            if(!curr)
                return head;
            head=curr;
            tail1=curr;
        }
        //cout<<"ok"<<endl;
        while(curr->next)
        {
            curr=curr->next;
            if(curr->val<x)
            {
                tail1->next=curr;
                tail1=curr;
            }
            else
            {
                tail2->next=curr;
                tail2=curr;
            }
            
        }
        tail1->next=head2;
        tail2->next=nullptr;
        return head;
    }
};