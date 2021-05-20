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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        queue<TreeNode*> q1, q2;
        if(root)
            q1.push(root);
        while(!q1.empty())
        {
            vector<int> temp;
            while(!q1.empty())
            {   
                TreeNode *l = q1.front()->left, *r = q1.front()->right;
                if(l)
                    q2.push(l);
                if(r)
                    q2.push(r);
                temp.push_back(q1.front()->val);
                q1.pop();
            }
            v.push_back(temp);
            swap(q1,q2);
        }
        
        
        
        return v;
    }
};