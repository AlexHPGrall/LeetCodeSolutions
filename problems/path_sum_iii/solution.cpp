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
    unordered_map<int,int> mp;
    int res=0;
    int pathSum(TreeNode* root, int targetSum, int prev=0) {
        if(!root)
            return 0;
        root->val +=prev;
       
        if(!mp.count(prev +targetSum))
            mp[prev+targetSum] =1;
        else
            mp[prev+targetSum]++;
        if(mp.count(root->val) && mp[root->val]>0)
            res+=mp[root->val];
        pathSum(root->left, targetSum, root->val);
        pathSum(root->right, targetSum, root->val);
        mp[prev+targetSum]--;
        return res;
    }
};