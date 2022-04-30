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
    vector<vector<TreeNode*>> dp=vector<vector<TreeNode *>>(21);
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2==0)
            return {};
        if(n==1)
        {
            TreeNode *root=new TreeNode();
            return {root};
        }
        if(!dp[n].empty())
            return dp[n];
        vector<TreeNode *> res;
        for(int i=1, j=n-2; i<=n-2;i+=2, j-=2)
        {
           
            vector<TreeNode *> left=allPossibleFBT(i), right=allPossibleFBT(j);
            for(int k=0; k<left.size(); ++k)
                for(int l=0; l<right.size();++l)
                {
                    TreeNode *root=new TreeNode();
                    root->left=left[k];
                    root->right=right[l];
                    res.push_back(root);
                }
        }
        dp[n]=res;
        return res;
    }
};