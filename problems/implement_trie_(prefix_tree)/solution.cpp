class TrieNode
{
    public:
    char c;
    TrieNode *next[26] = {0};
    bool end =false;
    TrieNode(char c) : c(c) {}
    
    
};

class Trie { 
    TrieNode Root{0};
public:
    Trie() {  
    }
    
    void insert(string word) {
        TrieNode *curr = &Root;
        int i;
        for(i=0; i<word.size() && curr->next[word[i]-'a'] != 0; curr = curr->next[word[i]-'a'], ++i)
        {}
        for(; i<word.size();++i)
        {
            curr->next[word[i]-'a'] = new TrieNode(word[i]);
            curr = curr->next[word[i] -'a'];
        }
        curr->end =true;
    }
    
    bool search(string word) {
        TrieNode *curr = &Root;
        int i;
        for(i=0; i<word.size() && curr->next[word[i]-'a'] != 0; curr = curr->next[word[i]-'a'], ++i)
        {}
        return (i==word.size()) && (curr->end);
    }
    
    bool startsWith(string prefix) {
        TrieNode *curr = &Root;
        int i;
        for(i=0; i<prefix.size() && curr->next[prefix[i]-'a'] != 0; curr = curr->next[prefix[i]-'a'], ++i)
        {}
        return i==prefix.size();
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */