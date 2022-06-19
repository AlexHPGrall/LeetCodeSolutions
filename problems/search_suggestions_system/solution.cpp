struct TrieNode
{
    bool end=false;
    TrieNode *next[26]={};
};
class Solution {
    void insert(TrieNode *root, string &s)
    {
        for(char c:s)
        {
            if(!root->next[c-'a'])
                root->next[c-'a']=new TrieNode;
            root=root->next[c-'a'];
        }
        root->end=true;
    }
    void searchFromPrefix(TrieNode *root, string &prefix, vector<string> &v)
    {
        if(v.size()==3)
            return;
        if(root->end==true)
            v.push_back(prefix);
        if(v.size()==3)
            return;
        for(int i=0; i<26;++i)
        {
            if(root->next[i])
            {
                prefix.push_back('a'+i);
                searchFromPrefix(root->next[i], prefix, v);
                prefix.pop_back();
                 if(v.size()==3)
                    return;  
            }
        }
    }
    TrieNode *findPrefix(TrieNode *root, int index, string &prefix)
    {
        if(!root || index==prefix.size())
            return root;
        return findPrefix(root->next[prefix[index]-'a'], index+1, prefix);
        
    }
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        TrieNode root;
        vector<vector<string>> res;
        for(string &w:products)
        {
            insert(&root, w);
        }
        for(int i=0;i<searchWord.size();++i)
        {
            string s=searchWord.substr(0,i+1);
            TrieNode *prefixNode=findPrefix(&root,0, s);
            vector<string> v;
            if(prefixNode)
               searchFromPrefix(prefixNode, s,v);
            res.push_back(v);
        }
        return res;
    }
};