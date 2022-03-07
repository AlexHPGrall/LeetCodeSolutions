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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* Merged;
        if(!list1 && !list2)
            return list1;
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        if(list1->val<list2->val)
        {Merged=list1; list1=list1->next;}
        else
        {Merged=list2;list2=list2->next;}
        ListNode *Curr, nxt;
        Curr=Merged;
        while(list1 && list2)
        {
            if(list1->val<list2->val)
            {Curr->next=list1; list1=list1->next;}
            else
            {Curr->next=list2;list2=list2->next;}
            Curr=Curr->next;
        }
        while(list1)
        {
            Curr->next=list1; list1=list1->next;
            Curr=Curr->next;
        }
        while(list2)
        {
            Curr->next=list2; list2=list2->next;
            Curr=Curr->next;
        }
        Curr->next=nullptr;
        
        return Merged;
    }
};