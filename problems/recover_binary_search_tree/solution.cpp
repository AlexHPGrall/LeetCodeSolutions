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
    TreeNode* n1=nullptr;
    TreeNode* n2=nullptr;
    TreeNode* prev=nullptr;
    void helper(TreeNode* root)
    {
        if(!root)
            return;
        helper(root->left);
        if(prev && prev->val> root->val)
        {
            
            if(!n1)
                n1=prev;
            n2=root;
        }
        prev=root;
        helper(root->right);
    }
    void recoverTree(TreeNode* root) {
        helper(root);
        swap(n1->val,n2->val);

        
    }
};