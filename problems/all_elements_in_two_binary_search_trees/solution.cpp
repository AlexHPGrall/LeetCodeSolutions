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
    void PushLeft(TreeNode* root, vector<TreeNode*> &st)
    {
                while(root->left)
                {
                    st.push_back(root->left);
                    root=root->left;
                }

    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {

        vector<int> list;
        vector<TreeNode*> st1, st2;
        if(root1){
            st1.push_back(root1);
            PushLeft(root1, st1);
        }        
        if(root2)
        {
            st2.push_back(root2); 
            PushLeft(root2, st2);
        }
        
        TreeNode* curr1;
        TreeNode* curr2;
        
        while(!st1.empty() || !st2.empty())
        {
            if(!st1.empty())
               curr1 =st1.back();
            if(!st2.empty())
                curr2 =st2.back();
            
            if(!st1.empty() && (st2.empty() || curr1->val < curr2->val))
            {
                st1.pop_back();
                list.push_back(curr1->val);
                if(curr1->right)
                {
                    st1.push_back(curr1->right);
                    PushLeft(curr1->right, st1);
                }
            }
            else
            {
                st2.pop_back();
                list.push_back(curr2->val);
                if(curr2->right)
                {
                    st2.push_back(curr2->right);
                    PushLeft(curr2->right, st2);
                }
            }   
        }
        
    return list;    
    }
};