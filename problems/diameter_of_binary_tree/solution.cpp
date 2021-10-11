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
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        int depthL{0}, depthR{0};
        int L=diameterOfBinaryTree(root->left), R= diameterOfBinaryTree(root->right);
        if(root->left)
            depthL=root->left->val;
        if(root->right)
            depthR=root->right->val;
        root->val = max(depthR+1, depthL+1);
        int depth=root->val;
        if( depth==1)
            return 0;
        
        if(L<=depthL && R<=depthR)
            return depthL + depthR;
        L=max(L, depthL);
        R=max(R, depthR);
        
        return max(max(L, R), depthL + depthR) ;
    }
};