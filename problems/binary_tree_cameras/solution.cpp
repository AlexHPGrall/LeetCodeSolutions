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
    int helper(TreeNode* root, TreeNode* p)
    {
        if(!root)
            return 0;
        root->val=0;
        int l=helper(root->left, root);
        int r=helper(root->right, root);
        if((!root->left||root->left->val) && (!root->right || root->right->val))
        {
            return l+r;
        }
        root->val=1;
        if(p)
            p->val=1;
        return l+r+1;
    }
    int minCameraCover(TreeNode* root) {
        
        if(!root)
            return 0;
        int res=helper(root, nullptr);
        if(!root->val)
            res++;
        return res;
    }
};