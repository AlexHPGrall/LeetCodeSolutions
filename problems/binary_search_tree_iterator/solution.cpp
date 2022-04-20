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
class BSTIterator {
    TreeNode *it;
public:
    BSTIterator(TreeNode* root) {
       it=root;
        while(it->left)
        {
            TreeNode *tmp=it->left;
            while(tmp->right)
                tmp=tmp->right;
            tmp->right=it;
            it=it->left;
        }
    }
    
    int next() {
        int res;
        if(!it->left)
        {
            res=it->val;
            it=it->right;
            return res;
        } 
        else
        {
             while(it->left)
            {
                TreeNode *tmp=it->left;
                while(tmp->right)
                {
                    if(tmp->right==it)
                    {
                        tmp->right=nullptr;
                        res=it->val;
                        it=it->right;
                        return res;
                    }
                    tmp=tmp->right;
                }
                    
                tmp->right=it;
                it=it->left;
            }
            res=it->val;
            it=it->right;
            return res;
        }
    }
    
    bool hasNext() {
        return it;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */