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
    int count =0;
    TreeNode *Left, *Right, *MidL, *MidR;
    void find(int depth, int height, TreeNode* node)
    {
        if(Right)
            return;
        if(depth == height)
            return;
        TreeNode* curr =node;
        curr=curr->left;
        for(int i=depth+1; i<height; ++i)
            curr=curr->right;
        MidL =curr;
        curr =node;
        curr=curr->right;
        for(int i=depth+1; i<height; ++i)
            curr=curr->left;
        MidR=curr;
        if(MidL && !MidR)
        {
            count+=(1<<height-depth-1);
            return;
        }
        if(MidL && MidR)
        {
            Left=MidR;
            find(depth+1, height, node->right);
        }
        else if(!MidL&&!MidR)
        {
            count+=(1<<height-depth-1);
            Right=MidL;
            find(depth+1, height, node->left);
        }
        
    }
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        TreeNode* curr=root;
        int height = 0 ;
        while(curr->left)
        {
            curr=curr->left;
            height++;
        }
        Left=curr;
        curr=root;
        for(int i=0; i<height; ++i)
            curr=curr->right;
        Right=curr;
        find(0, height,root);
        int minv= (1<<height) -1;
        int res = (1<<height) -count;
        return minv+res;
    }
};