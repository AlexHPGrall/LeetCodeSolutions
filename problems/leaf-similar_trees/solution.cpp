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
    void getLeaves(TreeNode *root, vector<int> &lseq)
    {
        if(!root)
            return;
        if(!root->left && !root->right)
            lseq.push_back(root->val);
        else
        {
            getLeaves(root->left,lseq);
            getLeaves(root->right, lseq);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> seq1,seq2;
        getLeaves(root1,seq1);
        getLeaves(root2,seq2);
        return seq1==seq2;
        
    }
};