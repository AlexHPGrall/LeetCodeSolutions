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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int m=0;
        int n=0;
        ListNode *currA=headA;
        ListNode *currB=headB;
        while(currA)
        {
            ++m;
            currA=currA->next;
        }
        while(currB)
        {
            ++n;
            currB=currB->next;
        }
        currA=headA;
        currB=headB;

        if(m>n)
        {
            while(m!=n)
            {
                --m;
                currA=currA->next;
            }
        }
        else
        {
            while(m!=n)
            {
                --n;
                currB=currB->next;
            }
        }
        while(currA)
        {
            if(currA==currB)
                return currA;
            currA=currA->next;
            currB=currB->next;
        }
        return nullptr;
    }
};