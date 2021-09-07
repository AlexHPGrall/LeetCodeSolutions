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
    ListNode* reverseList(ListNode* head) {
        ListNode *Prev, *Next, *curr;
        Prev=nullptr;
        curr=head;
        while(curr)
        {
            Next=curr->next;
            curr->next=Prev;
            Prev=curr;
            curr=Next;
        }
        return Prev;
        
        
    }
};