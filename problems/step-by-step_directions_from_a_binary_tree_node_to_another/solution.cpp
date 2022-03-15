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
    string s,d;
    void recFind(TreeNode *root,int start, int dest, string &path)
    {
        if(!root)
            return;
        if(root->val==start)
            s=path;
        if(root->val==dest)
            d=path;
        path.push_back('L');
        recFind(root->left,start,dest,path);
        path[path.size()-1]='R';
        recFind(root->right,start,dest,path);
        path.pop_back();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string path="";
        recFind(root,startValue,destValue,path);
        int i=0,j=0;
        while(i<s.size() && j<d.size()&&s[i]==d[j])
        {++i;++j;}
        string res="";
        while(i<s.size())
        {++i;res.push_back('U');}
        while(j<d.size())
        {
            res.push_back(d[j++]);
        }
        return res;
    }
};