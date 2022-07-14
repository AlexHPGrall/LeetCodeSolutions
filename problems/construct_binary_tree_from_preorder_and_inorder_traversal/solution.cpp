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
    unordered_map<int, int> mp;
    int n;
    TreeNode *recBuild(vector<int>& preorder, vector<int>& inorder, int &i,  int p, int l, int r)
    {
        TreeNode *root= new TreeNode();
        int v=preorder[i];
        root->val=v;
        if(i<n-1 && mp[preorder[i+1]]<mp[v])
        {
            ++i;
            root->left=recBuild(preorder, inorder,i,v,l,mp[v]);
        }
        if(i<n-1&&(mp[preorder[i+1]]<=r && mp[preorder[i+1]]>mp[v]))
        {
            ++i;
            root->right=recBuild(preorder, inorder, i,v,mp[v],r);
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        n=inorder.size();
        for(int i=0;i<n;++i)
            mp[inorder[i]]=i;
        /*
        for(int i=0;i<n;++i)
            cout<<mp[preorder[i]]<<' ';
        cout<<endl;
        */
        int i=0;
        return recBuild(preorder,inorder,i,1e7,0,n-1);
        
    }
};