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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode *> q;
        vector<int> res;
        if(!root)
            return res;
        q.push(root);
        while(!q.empty())
        {
            int count =q.size();
            int currmax=q.front()->val;
            while(count--)
            {
                TreeNode *node=q.front();
                q.pop();
                currmax=max(currmax,node->val);
                if(node->right)
                    q.push(node->right);
                if(node->left)
                    q.push(node->left);
                
            }
            res.push_back(currmax);
            
        }
        return res;
    }
};