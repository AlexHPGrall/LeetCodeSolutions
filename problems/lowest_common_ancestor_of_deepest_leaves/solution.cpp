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
    int maxDepth=0;
    TreeNode *res;
    int helper(TreeNode *root, int depth)
    {
        if(!root)
        {
            return depth-1;
        }
        int ld=helper(root->left, depth+1);
        int rd=helper(root->right, depth+1);
        maxDepth=max({maxDepth, ld, rd});
        if(ld == rd && ld ==maxDepth)
        {
            res=root;
        }
        return max(ld, rd);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        helper(root,0);
        return res;
    }
};