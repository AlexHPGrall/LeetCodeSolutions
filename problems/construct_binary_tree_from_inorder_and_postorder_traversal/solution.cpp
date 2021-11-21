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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, 
                        int m=-1,int n=-1, int i =0, int j=0) {
        if(n==-1)
        {
            n=inorder.size();
            m=n;
        }
        if(i>=m || j>=n)
            return nullptr;
        TreeNode *root =new TreeNode();
        root->val=postorder[n-1];
        if(m-i==1)
            return root;
        if(m-i ==2)
        {
            if(inorder[i] == postorder[j])
            {root->left=new TreeNode(); root->left->val =inorder[i];}
            else
            {root->right=new TreeNode(); root->right->val=postorder[j];}
            return root;
        }
        int k=i, l=j;
        while(k<m && inorder[k] != root->val)
        {++k; l++;}
        
        root->left = buildTree(inorder, postorder, k, l, i, j);
        root->right = buildTree(inorder, postorder, m, n-1, k+1, l);
        
        return root;
        
    }
};