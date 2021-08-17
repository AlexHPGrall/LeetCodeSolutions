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
    int count;
    void dfs(TreeNode* node, int pathMax)
    {
        if(!node)
            return;
        if(node->val >= pathMax)
            ++count;
        int newMax = max(pathMax, node->val);
        dfs(node->left, newMax);
        dfs(node->right, newMax);
    }
    int goodNodes(TreeNode* root) {
        count =0;
        dfs(root, root->val);
        return count;
    }
};