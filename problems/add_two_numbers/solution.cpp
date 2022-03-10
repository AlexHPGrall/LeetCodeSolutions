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
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        ListNode* res=l1,*Prev;
        int carry=0;
        while(l1 || l2)
        {
            
            if(!l2)
            {l1->val+=carry;}
            else if(!l1)
            {
                Prev->next=new ListNode(l2->val+carry);
                l1=Prev->next;
            }
            else
            {
                l1->val+=l2->val+carry;
            }
            
            
            carry=l1->val/10;
            l1->val%=10;
            //cout<<l1->val<<endl;
            Prev=l1;
            l1=l1->next;
            if(l2)
                l2=l2->next;
        }
        if(carry)
            Prev->next=new ListNode(carry);
        return res;
    }
};