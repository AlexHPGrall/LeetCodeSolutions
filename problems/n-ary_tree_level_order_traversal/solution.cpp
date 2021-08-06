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
    vector<vector<int>> levelOrder(Node* root) {
        if(!root)
            return {};
        queue<Node*> q;
        vector<vector<int>> ans;
        vector<int> res;
        q.push(root);
        int n=1, m=0;
        while(!q.empty())
        {
            Node *cur = q.front();
            q.pop();
            res.push_back(cur->val);
            --n;
            for(int i =0; i<cur->children.size(); ++i, ++m)
                q.push(cur->children[i]);
            if(n ==0)
            {
                swap(n,m);
                ans.push_back(res);
                res.clear();
            }
        }
        
        return ans;
    }
};