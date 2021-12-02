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
    ListNode* oddEvenList(ListNode* head) {
        if(!head)
            return head;
        ListNode* odd = head;
        ListNode* evenH=head->next;
        ListNode* even=head->next;
            
        int index=1;
        while(even && (even->next || odd->next))
        {
            
            if(index&1)
            {
                
                if(odd->next)
                    odd->next = odd->next->next;
                if(odd->next)
                    odd= odd->next;
                
            }
                
            else
            {
                
                if(even->next)
                even->next=even->next->next;
                if(even->next)
                even=even->next;
                
                
            }
            
            index++;
                
        }
       
        odd->next = evenH;
        
        return head;
        
    }
};