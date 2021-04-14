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
        ListNode *curr, *lower, *lowerHead, *upper, *upperHead, *next;
        curr = head;
        upperHead = lowerHead = nullptr;
        if(!curr || !curr->next)
            return head;
        while(curr)
        {
            next = curr->next;
            
            if(curr->val < x )
            {
                cout <<curr->val<< ' ';
                if(lowerHead == nullptr)
                {
                    lower= lowerHead =curr;
                }
                else{
                    lower->next = curr;
                    lower = lower->next;
                }
                
            }
            if(curr->val >= x )
            {
                if(upperHead == nullptr)
                {
                    upper= upperHead =curr;
                }
                upper->next = curr;
                upper = upper->next;
            }
                
                
            curr = next;    
        }
        if(lowerHead == nullptr )
        {
            lowerHead= upperHead;
            upper->next = nullptr;
        }
        else if(upperHead == nullptr)
        {
            lower->next = nullptr;
        }
        else
        {
            upper->next = nullptr;
            lower->next = upperHead;
        }
        
        
       
        
     return lowerHead;   
    }
    
};