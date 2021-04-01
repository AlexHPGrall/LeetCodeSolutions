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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
            return true;
        ListNode* traverse = head;
        vector<int> list;
        while(traverse)
        {
            list.push_back(traverse->val);
            traverse = traverse->next;
        }
        for(int i=0; i<=list.size()/2; i++)
        {
            if(list[i] != list[list.size()-1-i])
                return false;
        }
        return true;
    }
};