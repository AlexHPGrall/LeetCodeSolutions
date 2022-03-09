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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* res=head;
        if(!head)
            return res;
        int preVal=head->val;
        
        while(res && res->next && res->next->val==preVal)
        {
            while(res && res->val==preVal)
                res=res->next;
            if(res)
                preVal=res->val;
        }
        if(!res)
            return res;
        head=res->next;
        ListNode *Prev=res;

        while(head)
        {
            preVal=head->val;
            if(head->next && head->next->val==preVal)
            {
                while(head && head->val==preVal)
                    head=head->next;
                Prev->next=head;
            }
            else
            {
                Prev=Prev->next;
                head=head->next;
            }
        }
        return res;
    }
};