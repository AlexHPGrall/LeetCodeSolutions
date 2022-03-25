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
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        unordered_map<int ,int> created, parented;
        unordered_map<int, TreeNode*> nodeMap;
        for(auto &v:desc)
        {
            TreeNode* parent;
            TreeNode* child;
            if(created[v[0]])
                parent=nodeMap[v[0]];
            else
            {
                parent=new TreeNode(v[0]);
                created[v[0]]=1;
                nodeMap[v[0]]=parent;
            }
            if(created[v[1]])
                child=nodeMap[v[1]];
            else
            {
                child=new TreeNode(v[1]);
                created[v[1]]=1;
                nodeMap[v[1]]=child;
            }
            if(v[2])
                parent->left=child;
            else
                parent->right=child;
            parented[v[1]]=1;
            if(!parented.count(v[0]))
                parented[v[0]]=0;
        }
        
        for(auto &it:parented)
        {
            
            if(!it.second)
                return nodeMap[it.first];
        }
        return nullptr;
    }
};