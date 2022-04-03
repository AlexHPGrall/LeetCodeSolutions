struct TrieNode
{
    TrieNode *next[26]={nullptr};
    bool end;
};

void insert(TrieNode *root, string &s)
{
    for(int i=0; i<s.length();++i)
    {
        if(!root->next[s[i]-'a'])
            root->next[s[i]-'a']=new TrieNode();
        root=root->next[s[i]-'a'];
    }
    root->end=true;
    
}
class Encrypter {
    unordered_set<string> dic;
    unordered_map<char, string> enc;
    unordered_map<string, vector<char>> dec;
    unordered_map<string, string> cache1;
    TrieNode *root;
public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for(int i=0; i<keys.size(); ++i)
        {
            enc[keys[i]]=values[i];
            dec[values[i]].push_back(keys[i]);
        }
        root=new TrieNode;
        for(string &s:dictionary)
        {
            insert(root,s);
            dic.insert(s);
        }
    }
    
    string encrypt(string word1) {
        if(cache1.count(word1))
            return cache1[word1];
        string res;
        for(char c:word1)
        {
            res.push_back(enc[c][0]);
            res.push_back(enc[c][1]);
        }
        cache1[word1]=res;
        return res;
    }
    
    int dcpt(string &word2, int i, TrieNode *node)
    {
         if(i>=word2.size())
         {
             return (node->end)?1:0;
         }
        int res=0;
        string t="**";
        t[0]=word2[i];
        t[1]=word2[i+1];
        for(char c:dec[t])
        {
            if(!node->next[c-'a'])
                continue;
            res+=dcpt(word2,i+2,node->next[c-'a']);
        }
        return res;
    }
    int decrypt(string word2) {
       return dcpt(word2,0, root);
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */