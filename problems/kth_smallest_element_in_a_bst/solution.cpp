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
    int res=-1;
    int kthSmallest(TreeNode* root, int k, int count =0) {
        if(!root)
            return count;
        
        if(res!=-1)
            return res;
        
        count =kthSmallest(root->left, k, count);
        if(res!=-1)
            return res;
        count++;
        if(count==k)
        {res=root->val;
        return res;}
        //cout<<count<<' '<<root->val<<endl;
        count=kthSmallest(root->right, k, count);
         if(res!=-1)
            return res;
        return count;
    }
};