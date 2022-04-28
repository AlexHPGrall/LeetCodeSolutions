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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if(val > root->val)
        {
            TreeNode *node =new TreeNode(root->val, root->left, root->right);
            root->val=val;
            root->right=nullptr;
            root->left=node;
        }
        else
        {
            if(root->right)
                insertIntoMaxTree(root->right, val);
            else
            {
                TreeNode *node =new TreeNode(val);
                root->right=node;
            }
                
        }
        return root;
            
    }
};