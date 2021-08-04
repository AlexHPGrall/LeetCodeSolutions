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
    int cursum;
    vector<int> cur;
    vector<vector<int>> ans;
    void DFS(TreeNode* node, int targetSum)
    {
        cur.push_back(node->val);
        cursum+=node->val;
        if(cursum==targetSum && node->left == nullptr && node->right ==nullptr)
            ans.push_back(cur);
        else
        {
            if(node->left)
                DFS(node->left, targetSum);
            if(node->right)
                DFS(node->right, targetSum);
        }
        cursum -= node->val;
        cur.pop_back();
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root)
            DFS(root, targetSum);
        return ans;
        
    }
};