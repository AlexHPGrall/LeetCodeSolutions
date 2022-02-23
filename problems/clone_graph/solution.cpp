/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node)
    {
        if(!node)
            return nullptr;
        unordered_map<Node*, Node*> CloneMap;
        vector<Node *> NodeStack;
        Node *res=new Node(node->val);
        NodeStack.push_back(node);
        CloneMap[node]=res;
        while(!NodeStack.empty())
        {
            
            Node *currNode = NodeStack.back();
            NodeStack.pop_back();
            Node *currClone = CloneMap[currNode];
            
            for(Node *neiNode:currNode->neighbors)
            {
                if(!CloneMap.count(neiNode))
                {
                    NodeStack.push_back(neiNode);
                    Node* neiClone=new Node(neiNode->val);
                    CloneMap[neiNode]=neiClone;
                }
                currClone->neighbors.push_back(CloneMap[neiNode]);
            }
        }
       
        
        return res;
        
    }
};