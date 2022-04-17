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
    
    TreeNode* increasingBST(TreeNode* root) {
    stack<TreeNode *> st;
        vector<TreeNode *> v;
        
        TreeNode* curr=root;
        st.push(curr);
        while(!st.empty())
        {
            curr=st.top();
            st.pop();
            //cout<<curr->val<<endl;
            while(curr)
            {
                st.push(curr);
                curr=curr->left;
            }
            while(!st.empty() && !st.top()->right)
            {
                
                curr=st.top();
                st.pop();
                v.push_back(curr);
            }
            if(!st.empty())
            {
                curr=st.top();
                st.pop();
                //cout<<curr->val<<endl;
                v.push_back(curr);
                st.push(curr->right);
            }
        }
        v.push_back(nullptr);
        for(int i=0;i<v.size()-1; ++i)
        {
            v[i]->left=nullptr;
            v[i]->right=v[i+1];
        }

        return v[0];
    }
};