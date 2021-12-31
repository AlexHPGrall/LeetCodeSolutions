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
    int res = -1;
    int maxAncestorDiff(TreeNode* root, int *mn =nullptr, int *mx=nullptr) {
      if(!root)
          return 0;
       int rmin = INT_MAX, lmin = INT_MAX, rmax=-1,lmax=-1;
       if(root->left)
           maxAncestorDiff(root->left, &lmin,&lmax);
        if(root->right)
           maxAncestorDiff(root->right, &rmin,&rmax);
        int tmn = INT_MAX;
        int tmx= -1;
        if(!mn)
            mn=&tmn;
        if(!mx)
            mx=&tmx;
        lmin=min(lmin,root->val);
        lmax=max(lmax,root->val);
        
        res=max({res,abs(root->val - lmax), abs(root->val - lmin)});
        rmin=min(rmin,root->val);
        rmax=max(rmax,root->val);
        res=max({res, abs(root->val - rmin), abs(root->val - rmax)});
        *mn=min({*mn,rmin,lmin});
        *mx=max({*mx,rmax,lmax});
        return res;
    }
};