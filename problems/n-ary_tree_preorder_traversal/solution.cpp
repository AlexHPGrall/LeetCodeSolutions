/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
   
        
    
    vector<int> preorder(Node* root) {
        vector<int> res;
        vector<Node*>st;
        if(!root)
            return res;
        Node *cur;
        st.push_back(root);
        while(!st.empty())
        {
            cur=st.back();
            
            res.push_back(cur->val);
           
            st.pop_back();
                for(int i = cur->children.size() -1; i>=0; --i)
                        st.push_back(cur->children[i]);
            
            
            
        }
        
        return res;
        
    }
};