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
    int res=0;
    const pair<int, int> rec(TreeNode* root)
    {
        if(!root)
        {
            return {0,0};
        }
        auto& [cnt1, sum1]=rec(root->left);
        auto& [cnt2, sum2]=rec(root->right);
        if((sum1+sum2+root->val)/(cnt1+cnt2+1)==root->val)
            res++;
        return {(cnt1+cnt2+1), (sum1+sum2+root->val)};
        
    }
    int averageOfSubtree(TreeNode* root) {
        rec(root);
        return res;
    }
};