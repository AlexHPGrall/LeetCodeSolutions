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
    TreeNode* trimBST(TreeNode* root, int low, int high, TreeNode* p=nullptr, int s=0) {
        //cout<<root->val<<endl;
        while(root && (root->val >high || root->val<low))
        {   
            if(root->val>high)
                root=root->left;
            else
                root=root->right;
        }         
        if(p)
            {
                if(s==1)
                    p->right=root;
                else
                    p->left=root;
            }
        if(!root)
            return root;
        trimBST(root->right, low, high, root,1);
        trimBST(root->left, low, high,root,-1);
        
        return root;
    }
};