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
    ListNode* middleNode(ListNode* head) {
        ListNode* Fast, *Slow;
        Fast=Slow=head;
        int i=1;
        while(Fast)
        {
            Fast=Fast->next;
            if(i++%2==0)
            {
                Slow=Slow->next;
            }
        }
        return Slow;    }
};