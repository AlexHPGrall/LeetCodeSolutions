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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode *Curr = head, *Prev;
        int n=0;
        vector<ListNode*> res;
        while(Curr)
        {
            ++n;
            Curr = Curr->next;
        }
        Curr=head;
        for(int i =0, l=0; i<k; ++i, ++l)
        {
            res.push_back(Curr);
            
            for(int j=0; j<n/k; ++j)
            {
                Prev=Curr;
                if(Curr)
                    Curr=Curr->next;
            }
            if(l<n%k)
            {
                Prev=Curr;
                if(Curr)
                    Curr = Curr->next;
            }
            if(Prev)
                Prev->next=nullptr;
        }
        
        return res;
        
        
        
    }
};