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
    bool rec(TreeNode* root)
    {
        if(!root)
            return false;
        bool b1=rec(root->left);
        if(!b1)
            root->left = nullptr;
        bool b2 = rec(root->right);
        if(!b2)
            root->right =nullptr;
        return ((root->val==1)|| b1||b2);
    }
    TreeNode* pruneTree(TreeNode* root) {
        
        if(!rec(root))
            return nullptr;
        return root;
    }
};