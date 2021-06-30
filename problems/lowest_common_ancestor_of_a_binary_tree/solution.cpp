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
    TreeNode* Found1, *Found2, *Parent;
    void RecTraversal(TreeNode* curr, TreeNode* p, TreeNode* q)
    {
        
        if(Parent || !curr)
            return;
        if(!Found1 && (curr == p || curr ==q))
        {
            Found1 =curr;
        
        
            RecTraversal(curr->left, p, q);
            RecTraversal(curr->right, p, q);
        
            if(Found2)
                Parent =Found1;
            return;
        }
        else if(Found1 && (curr == p || curr ==q))
        {
            Found2 =curr;
            return;
        }
        else if(!Parent && !Found1)
        {
            RecTraversal(curr->left, p, q);
            if(Found1 && !Parent)
            {
                RecTraversal(curr->right, p, q);
                if(Found2 && !Parent)
                {
                    Parent =curr;
                    return;
                }
                return;
                    
                
            }
            else if(Parent)
                return;
            else
            {
                RecTraversal(curr->right, p, q);
            }
            
            
        }
        else
        {
            RecTraversal(curr->left, p, q);
            RecTraversal(curr->right, p, q);
        }
        
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        Found1= Found2= nullptr;
        Parent=nullptr;
        RecTraversal(root, p, q);
        return Parent;
        
    }
};