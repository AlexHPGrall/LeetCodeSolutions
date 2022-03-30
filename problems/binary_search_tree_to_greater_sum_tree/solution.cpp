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
    int helper(TreeNode* root, int sum)
    {
        if(!root)
            return 0;
        int res=0;
        res+=helper(root->right, sum);
        sum+=res;
        sum+=root->val;
        res+=root->val;
        root->val=sum;
        res+=helper(root->left,sum);
        
        
        return res; 
    }
        
    
    TreeNode* bstToGst(TreeNode* root) {
        helper(root, 0);
        return root;
            
    }
};