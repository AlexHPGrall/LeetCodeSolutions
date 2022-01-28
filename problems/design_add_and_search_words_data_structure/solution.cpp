struct TrieNode
{
    TrieNode *next[26]={0};
    bool end=false;
    
};

class WordDictionary {
public:
    TrieNode *root;
    WordDictionary() {
        root=new TrieNode;
    }
    
    void addWord(string word) {
        TrieNode *curr=root;
        
        for(char c : word)
        {
            if(!curr->next[c-'a'])
                curr->next[c-'a'] = new TrieNode;
            curr= curr->next[c-'a'];
        }
        curr->end =true;
    }
    
    bool search(string word, int index =0,TrieNode *curr=nullptr) {
        if(!curr)
            curr=root;
        
        for(int j=index; j<word.length();++j)
        {
            char c=word[j];
            if(c=='.')
            {
               for(int k=0;k<26;++k)
               {
                   if(curr->next[k])
                   {
                       if(search(word, j+1,curr->next[k]))
                           return true;
                   }
               }
                return false;
            }
            else
            {
                if(curr->next[c-'a'])
                    curr=curr->next[c-'a'];
                else
                    return false;
            }
            
        }
        
        return curr->end;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */