struct MyTreeNode
{
    string f;
    unordered_map<string, MyTreeNode *> nextF;
    bool end=false;
};
class Solution {
public:
    vector<string> res;
    void Dfs(MyTreeNode *root, string &s)
    {
        int n=s.size();
        
        s.append(root->f);
        if(root->end)
        {
            res.push_back(s);
            s.resize(n);
            return;
        }
        s.push_back('/');
        for(auto &[p, n]:root->nextF)
        {
            
            Dfs(n, s);
            
        }
        s.resize(n);
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        MyTreeNode root={};
        //root.f="/";
        
        for(string &path:folder)
        {
            string s="";
            MyTreeNode *curr=&root;
            for(char c:path)
            {
                if(c=='/'&&!s.empty())
                {
                    if(!curr->nextF.count(s))
                    {
                       curr->nextF[s]=new MyTreeNode();
                       curr->nextF[s]->f=s;
                       curr->nextF[s]->end=false;
                    }
                    curr=curr->nextF[s];
                    s="";
                    
                }
                else if(c!='/')
                    s.push_back(c);
            }
            if(!curr->nextF.count(s))
            {
                       curr->nextF[s]=new MyTreeNode();
                       curr->nextF[s]->f=s;
            }
            curr->nextF[s]->end=true;
            
        }
        string s="";
        Dfs(&root, s);
        return res;
        
        
    }
};