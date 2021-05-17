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
    int ans =0;
public:
    int dfs(TreeNode* node)
    {   if(!node)
            return 0;
        int val =dfs(node->left) + dfs(node->right);
        if(val == 0) return 3;
        if(val <3) return 0;
        ans++;
        return 1;
        
    }
    int minCameraCover(TreeNode* root) {
        int res = dfs(root);
        return res>2 ? ans+1: ans;
    }
};