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
    int widthOfBinaryTree(TreeNode* root) {
        queue<TreeNode*> q;
        queue<uint32_t> wq; 
        int res=0;
        q.push(root);
        wq.push(1);
        
        while(!q.empty())
        {
            int n=q.size();
            uint32_t First=0, Last=0;
            
            while(n--)
            {
                TreeNode* curr = q.front();
                //cout<<curr->val<<" ";
                q.pop();
                uint32_t currval=wq.front();
                wq.pop();
                if(!curr)
                {
                    continue;
                }
                if(!First)
                    First=currval;
                Last=currval;
                if(curr->left)
                {
                    q.push(curr->left);
                    wq.push(2*currval);
                }
                if(curr->right)
                {
                    q.push(curr->right);
                    wq.push(2*currval+1);
                }
                
            }
            //cout<<endl;
            if(First)
                res=max(res,(int)(Last-First+1));
        }
        return res;
    }
};