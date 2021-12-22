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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode* curr=head;
        while(curr)
        {
            st.push(curr);
            curr=curr->next;
        }
        curr=head;
        while(curr && !st.empty() && st.top() != curr && st.top() != curr->next)
        {
            
            ListNode* next=curr->next;
            curr->next=st.top();
            st.pop();
            curr->next->next=next;
            curr=next;
        }
        if(curr)
        {
            if(st.top()==curr)
                curr->next=nullptr;
            else if(st.top()==curr->next)
                curr->next->next=nullptr;
        }
            
        
    }
};