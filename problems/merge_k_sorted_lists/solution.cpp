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
    ListNode* recMerge(vector<ListNode*>& lists, int l, int r)
    {
        if(l==r)
            return lists[l];
        else
        {
            int mid=l+(r-l)/2;
            ListNode *left =recMerge(lists,l, mid);
            ListNode *right=recMerge(lists, mid+1,r);
            if(!left)
                return right;
            if(!right)
                return left;
            if(left->val>right->val)
            {
                swap(left,right);
            }
            ListNode *prev=left,*res=left;
            while(left && right)
            {
                prev=left;
                if(left->next && right->val>left->next->val)
                {
                    //cout<<left->val<<"l ";
                    left=left->next;
                }
                else if(left->next)
                {
                    //cout<<right->val<<"r ";
                    ListNode *nxt=left->next;
                    left->next=right;
                    right=right->next;
                    left->next->next=nxt;
                    left=left->next;
                }
                else
                    break;
                    
            }
            if(right)
            {left->next=right;}
             //cout<<endl;   
            return res;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return nullptr;
        return recMerge(lists,0, lists.size()-1);
    }
};