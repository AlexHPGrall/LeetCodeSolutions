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
    int index=0;
    TreeNode* bstFromPreorder(vector<int>& preorder,  int left=INT_MIN, int right =INT_MAX)
    {
        
        TreeNode *root=new TreeNode;
        root->val = preorder[index];
        if(index >= preorder.size() -1)
            return root;
        
        if(preorder[index + 1]<preorder[index] && preorder[index+1] > left)
        {
            index +=1;
            root->left=bstFromPreorder(preorder,  left,root->val);
        }
        if(index >= preorder.size() -1)
            return root;
        if(preorder[index + 1]>root->val && preorder[index+1]<right)
        {
            index+=1;
            root->right=bstFromPreorder(preorder, root->val,right);
        }
        
       
        return root;
    }
};