/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast, *slow;
        fast=slow=head;
        if(!head)
            return head;
        for(;;)
        {
            if(fast->next && fast->next->next)
                fast=fast->next->next;
            else
                return nullptr;
            slow=slow->next;
            if(slow==fast)
                break;
        }
        slow=head;
        while(slow !=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return fast;
    }
};