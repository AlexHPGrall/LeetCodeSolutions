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
        ListNode *LeftNode = nullptr;
        ListNode *Prev, *Next, *Curr;
        Curr = head;
        Prev = nullptr;
        Next = head->next;
        for(int i=1; i<=right+1; ++i)
        {
            if(Curr)
            cout<<Curr->val<<endl;
           
            if(i == left -1)
            {
                LeftNode =Curr;
            }
            
            if(i==right+1 )
            {
                if(LeftNode)
                {
                    LeftNode->next->next = Curr;
                    LeftNode->next = Prev;
                }
                else
                {
                    head->next = Curr;
                    head = Prev;
                }
                
            }
            else if(i>=left && i<=right)
            {
                Curr->next = Prev;
            }
            
            Prev = Curr;
            Curr = Next;
            if(Curr)
                Next = Curr->next;
            
        }
        
        
        
        return head;
        
    }
        
    
                    
};