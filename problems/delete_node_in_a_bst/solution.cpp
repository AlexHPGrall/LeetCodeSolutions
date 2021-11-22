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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *curr = root;
        TreeNode *prev = nullptr;
        while(curr)
        {
            if(curr->val == key )
            {
                if(curr->left)
                {
                    TreeNode* lst = curr->right;
                     if(prev && prev->val > curr->val)
                         prev->left = curr->left;
                    else if(prev)
                        prev->right = curr->left;
                    
                    curr=curr->left;
                    if(!prev)
                        root=curr;
                    while(curr->right)
                        curr=curr->right;
                    curr->right = lst;
                    break;
                    
                }
                else
                {
                    if(prev &&prev->val > curr->val)
                         prev->left = curr->right;
                    else if (prev)
                        prev->right = curr->right;
                    curr=curr->right;
                    if(!prev)
                        root = curr;
                    break;
                }
            }
            prev = curr;
            if(curr->val < key)
                curr=curr->right;
            else
                curr=curr->left;
            
        }
        
        return root;
        
    }
};