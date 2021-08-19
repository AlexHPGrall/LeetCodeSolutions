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
    uint64_t totalSum;
    uint64_t maxSum;
    int calcSum(TreeNode* root)
    {
        if(!root)
            return 0;
        root->val += calcSum(root->left) +calcSum(root->right);
        return root->val;
    }
    void getMax(TreeNode *node)
    {
        if(!node)
            return;
        maxSum=max(maxSum, (totalSum-node->val)*node->val);
        getMax(node->left);
        getMax(node->right);
    }
    int maxProduct(TreeNode* root) {
        totalSum = calcSum(root);
        maxSum=0;
        getMax(root);
        int mod = 1e9 + 7;
        return (int)(maxSum % mod);
    }
};