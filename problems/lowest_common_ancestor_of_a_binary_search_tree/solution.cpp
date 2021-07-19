/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *Curr = root;
        for(;;)
        {
            if(p->val < Curr->val && q->val <Curr->val)
                Curr = Curr->left;
            else if(p->val > Curr->val && q->val >Curr->val)
                Curr = Curr->right;
            else
                return Curr;
        }
    }
};