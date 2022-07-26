/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *res=nullptr;
    void find(TreeNode* root, TreeNode* p, TreeNode* q, bool &bp, bool &bq )
    {
        if(!root || res!=nullptr)
            return;
        bool tp, tq;
        find(root->left,p,q,bp,bq);
        tp=bp;
        tq=bq;
        bp=false;
        bq=false;
        find(root->right,p,q,bp,bq);
        if(root==p)
        {
            bp=true;
        }
        if(root==q)
            bq= true;
        bp=tp||bp;
        bq=tq||bq;
        if(bq&&bp)
        {
            bp=false;
            bq=false;
            res=root;
        }
        
        
        
    }
        
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool a=false, b=false;
        find(root, p,q,a,b);
        return res;
    }
};