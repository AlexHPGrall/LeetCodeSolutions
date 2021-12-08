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
    inline int val(TreeNode *root)
    {
        if(!root)
            return 0;
        else
            return root->val;
    }
    int findTilt(TreeNode* root) {
        if(!root)
            return 0;
        int res=findTilt(root->right) + findTilt(root->left);
        res += abs(val(root->right) - val(root->left));
        root->val+=val(root->right) + val(root->left);
        
        return res;
    }
};