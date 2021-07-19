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
    ListNode *NewHead;
    ListNode* SwapNodes(ListNode* head, ListNode* Start, int k)
    {
        ListNode *Curr = Start, *Next, *Prev = head;
        while(k-->0)
        {
            Next= Curr->next;
            Curr->next = Prev;
            Prev = Curr;
            
            Curr = Next;
        }
        
        if(head)
         head->next = Prev;
        else
            NewHead =Prev;
        
        Start->next = Curr;
        return Start;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1)
            return head;
        int n =0;
        ListNode *Curr = head;
        NewHead=head;
        
        while(Curr)
        {
            n++;
            Curr=Curr->next;
        }
        int nodeCount = n/k;
        
        Curr=SwapNodes(NULL, head, k);
        for(int i =1; i<nodeCount; ++i)
        {
            Curr=SwapNodes(Curr, Curr->next, k);
        }
        
        
        
        
        return NewHead;
        
    }
};