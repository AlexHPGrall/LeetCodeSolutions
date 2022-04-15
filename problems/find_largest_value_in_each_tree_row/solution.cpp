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
        if(!root)
            return {};
        queue<TreeNode *> q;
        vector<int> res;
        q.push(root);
        while(!q.empty())
        {
            int count=q.size();
            int lvlMax=q.front()->val;
            while(count--)
            {
                TreeNode *curr=q.front();
                q.pop();
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                lvlMax=max(lvlMax, curr->val);
            }
            res.push_back(lvlMax);
        }
        return res;
    }
};