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
    void treeWalk(TreeNode* node, int depth, int &maxdepth)
    {
       if(node)
       {
           if (depth > maxdepth)
                maxdepth = depth;
           treeWalk(node->left, depth +1, maxdepth);
           treeWalk(node->right, depth+1, maxdepth);
       }
    }
    
    void SumNodes(TreeNode* node, int depth, int maxdepth, int& sum)
    {
        if(node)
       {
           if (depth == maxdepth)
                sum += node->val;
           SumNodes(node->left, depth +1, maxdepth, sum);
           SumNodes(node->right, depth+1, maxdepth, sum);
       }
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int maxdepth = 0, sum =0;
        treeWalk(root, 0, maxdepth);
        SumNodes(root, 0, maxdepth, sum);
        return sum;
        
        
    }
};