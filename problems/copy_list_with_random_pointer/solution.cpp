/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return nullptr;
        Node *curr=head;
        Node *nxt;
        while(curr)
        {
            nxt=curr->next;
            curr->next=new Node(curr->val);
            curr->next->next=nxt;
            curr->next->random=curr->random;
            curr=nxt;
        }
        curr=head;
        Node *res=head->next;
        while(curr)
        {
            if(curr->random)
                curr->next->random=curr->random->next;
            curr=curr->next->next;
            
        }
        curr=head;
        
        while(curr)
        {
            nxt=curr->next->next;
            //cout<<curr->val<<endl;
            if(nxt)
            {
                curr->next->next=nxt->next;
            }
            curr->next=nxt;
            curr=nxt;
        }
        return res;
    }
};