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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode *c1=l1, *c2=l2;
        ListNode *res, *curr;
        res=new ListNode(0);
        curr=res;
        while(c1 || c2)
        {
            int v=carry;
            if(c1)
            {v+=c1->val; c1=c1->next;}
            if(c2)
            {v+=c2->val;c2=c2->next;}
            carry=v/10;
            v=v%10;
            curr->next=new ListNode(v);
            curr=curr->next;
        }
        if(carry)
            curr->next=new ListNode(carry);
            curr=curr->next;
        return res->next;
    }
};