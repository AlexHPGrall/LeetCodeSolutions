struct TrieNode
{
  TrieNode *next[26] ={nullptr};
  bool end =false;
};
class StreamChecker {
    TrieNode *root;
    string stream;
    void insert(string &s)
    {
        int n= s.length();
        int i=n-1;
        TrieNode *curr = root;
        while(~i)
        {
            if(!curr->next[s[i]-'a'])
            {
                curr->next[s[i]-'a'] = new TrieNode();
            }
            curr=curr->next[s[i]-'a'];
            if(i==0)
                curr->end =true;
            --i;
        }
    }
    bool find()
    {
        int n=stream.length();
        int i=n-1;
        TrieNode *curr=root;
        while(~i)
        {
            if(!curr->next[stream[i]-'a'])
                break;
             curr=curr->next[stream[i]-'a'];
            if(curr->end)
                return true;
            --i;
        }
        return false;
    }
    
public:
    StreamChecker(vector<string>& words) {
        root=new TrieNode();
        for(string s:words)
            insert(s);
    }
    
    bool query(char letter) {
        stream.push_back(letter);
        return find();
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */