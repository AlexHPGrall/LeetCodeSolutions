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
    int dx =0, dy=0;
    void findCousins(TreeNode* root, int x, int y, int depth)
    {
        if(!root)
            return;
        if((root->left && root->left->val == x) && (root->right&&root->right->val==y))
            return;
        if((root->left &&root->left->val == y) && (root->right&&root->right->val==x))
            return;
        if(dx != 0 && depth >dx)
            return;
        if(dy !=0 && depth > dy)
            return;
        if(root->val == x)
        {
             dx = depth;
            return;
        }
        if(root->val == y)
        {
            dy=depth;
            return;
        }
        findCousins(root->left, x, y , depth+1);
        findCousins(root->right, x,y,depth+1);
        
    }
    bool isCousins(TreeNode* root, int x, int y) {
        findCousins(root, x, y, 0);
        if(dx !=0 && dx == dy)
            return true;
        return false;
    }
};