class TrieNode
{
    public:
    char c;
    TrieNode *next[26] = {0};
    string s;
    TrieNode(char c) : c(c) {}
    
    
    
};

class Trie { 
    
public:
    TrieNode Root{0};
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
        curr->s =word;
    }
    
    bool search(string word) {
        TrieNode *curr = &Root;
        int i;
        for(i=0; i<word.size() && curr->next[word[i]-'a'] != 0; curr = curr->next[word[i]-'a'], ++i)
        {}
        return (i==word.size()) && (!curr->s.empty());
    }
    
    bool startsWith(string prefix) {
        TrieNode *curr = &Root;
        int i;
        for(i=0; i<prefix.size() && curr->next[prefix[i]-'a'] != 0; curr = curr->next[prefix[i]-'a'], ++i)
        {}
        return i==prefix.size();
    }
};
class Solution {
public:
    int m ,n;
    vector<string> res;
    bool findWord(vector<vector<char>>& board, int i, int j, TrieNode *curr)
    {
        if(i<0 || i>=m || j<0 || j>=n||board[i][j] == '*'|| !curr->next[board[i][j]-'a'])
            return false;
        curr = curr->next[board[i][j]-'a'];
        if(!curr->s.empty())
        {
            res.push_back(curr->s);
            curr->s ={};
        }
            
        char c= board[i][j];
        board[i][j] ='*';
        bool res = findWord(board, i+1,j,curr) || findWord(board, i,j+1,curr) || findWord(board,i-1,j,curr) ||                          findWord(board, i,j-1,curr);
        board[i][j] = c;
        return res;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m=board.size(), n= board[0].size();
        //unordered_map<char, vector<string>> mp;
        Trie tr;
        
        for(string s:words)
        {
            tr.insert(s);
        }
 
        for(int i=0;i<m;++i)
        {
            for(int j =0; j<n ; ++j)
            {
                findWord(board,i,  j,&tr.Root);
            }
        }
        
            
        
        return res;
    }
};