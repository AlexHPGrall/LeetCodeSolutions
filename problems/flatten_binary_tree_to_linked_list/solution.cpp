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
    void flatten(TreeNode *root)
    {
        rflatten(root);
        /*cout<<"ok"<<endl;
        TreeNode* curr=root;
        while(curr)
        {
            cout<<curr->val<<endl;
            curr=curr->right;
        }
        //cout<<"ok"<<endl;
        */
    }
    void rflatten(TreeNode* root, TreeNode *R=NULL) {
        //cout<<root->val<<endl;
        if(!root)
            return;
        if(root->left)
        {
            if(root->right)
            {
                rflatten(root->left,root->right);
            }
            else
                rflatten(root->left,R);
        }
        if(root->right)
        {
           rflatten(root->right,R);
            if(root->left)
                root->right=root->left;
        }
        else
        {
            if(root->left)
                root->right=root->left;
            else
                root->right=R;
               
        }
        root->left=nullptr;
        
        
        
    }
};