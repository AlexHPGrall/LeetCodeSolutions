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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
       ListNode* sent=head;
        ListNode *nxt;        
        ListNode* curr=head->next;
        ListNode* prev, *nextSent;
        int cnt=0;
        int tg=2;
        while(curr)
        {
            cnt++;
            nextSent=curr;
            curr=curr->next;
            if(cnt==tg ||!curr)
            {
                if(cnt%2==0)
                {
                    //cout<<curr->val<<endl;
                    prev=curr;
                    curr=sent->next; 
                    while(curr!=nextSent)
                    {
                        nxt=curr->next;
                        curr->next=prev;
                        prev=curr;
                        curr=nxt;
                        
                    }
                    nextSent=sent->next;
                    sent->next=curr;
                    curr->next=prev;
                }
                tg++;
                cnt=0;
                sent=nextSent;
                curr=sent->next;
            }
        }
        return head;
    }
};