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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
public:
    TreeNode *MakeBalancedTreeRec(int i, int j, vector<int>& v)
    {
        TreeNode *root = new TreeNode; 
        if(j-i <=2)
        {
             TreeNode *ltree, *rtree;
            if(j - i ==2)
            {
                ltree = new TreeNode;
                rtree = new TreeNode;
                ltree->val = v[i];
                rtree->val = v[j];
                ltree->right = ltree->left =rtree->right = rtree->left = NULL;
                root->val = v[i+1];
            }
            else if(j-i ==1)
            {
                ltree = new TreeNode;
                rtree =NULL;
                ltree->val = v[i];
                root->val = v[i+1];
                ltree->right = ltree->left = NULL;
            }
            else
            {
                ltree = NULL;
                rtree =NULL;
                root->val = v[i];
            }
            
            
            root->right = rtree;
            root->left = ltree;
            
        }
        else{
            root->val = v[(i+j)/2];
            root->right = MakeBalancedTreeRec((i+j)/2 +1, j, v);
            root->left = MakeBalancedTreeRec(i,(i+j)/2 -1,v);
        }
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode* BinaryTree;
        vector<int> vec;
        if(!head)
            return NULL;
        ListNode* curr = head;
        while(curr)
        {
            vec.push_back(curr->val);
            curr = curr->next;
        }
        
        return MakeBalancedTreeRec(0, vec.size() -1, vec);
    }
};