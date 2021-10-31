/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* helpFlatten(Node* head)
    {
        if(!head)
            return head;
        while(head->next)
        {
            if(!head->child)
                head = head->next;
            else
            {
                Node* tmp1, *tmp2;
                tmp1 =  head->next;
                head->next = head->child;
                head->next->prev = head;
                head->child = nullptr;
                tmp2 = helpFlatten(head->next);
                tmp2->next=tmp1;
                if(tmp1)
                {
                    tmp1->prev = tmp2;
                     head=tmp1;
                }
                   
                else
                    head=tmp2;
                    
            }
        }
        if(head->child)
        {
            head->next = head->child;
            head->child = nullptr;
            head->next->prev = head;
            return helpFlatten(head->next);
        }
        return head;
            
        
    }
    Node* flatten(Node* head) {
        if(!head)
            return head;
        helpFlatten(head);
        return head;
        
    }
};