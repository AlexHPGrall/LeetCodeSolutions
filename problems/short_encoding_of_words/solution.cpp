struct Trie
{
    Trie *next[26]={};
    bool leaf=true;
};
class Solution {
    void insert(Trie *root, string &s)
    {
        for(auto it=s.rbegin();it<s.rend();++it)
        {
            char c=*it;
            root->leaf=false;
            if(!root->next[c-'a'])
                root->next[c-'a']=new Trie;
            root=root->next[c-'a'];
        }
        
    }
    int dfs(Trie *root, int curr)
    {
        if(!root)
            return 0;
        if(root->leaf)
        {
            //cout<<curr<<endl;
            return curr+1;
        }
        int res=0;
        for(int i=0; i<26;++i)
        {
            if(root->next[i])
            {
                res+=dfs(root->next[i], curr+1);
            }
        }
        return res;
    }
public:
    int minimumLengthEncoding(vector<string>& words) {
        Trie root;
        for(string &w:words)
            insert(&root,w);
        return dfs(&root,0);
    }
};