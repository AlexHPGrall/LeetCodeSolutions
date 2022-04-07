class CombinationIterator {
    vector<string> words;
    int index;
public:
    
    void rec(string &chars, int len, int i, string &s)
    {
        if(s.size()==len)
        {
            words.push_back(s);
            return;
        }
        for(int j=i;s.size() + chars.length()-1 -j+1>=len;++j)
        {
           
            s.push_back(chars[j]);
            rec(chars,len,j+1,s);
            s.pop_back();
        }
        
            
    }
    
    CombinationIterator(string chars, int len) {
        string s="";
        rec(chars, len,0, s);
        index=0;
    }
    
    string next() {
        
        index++;
        return words[index-1];
        
    }
    
    bool hasNext() {
        return !(index==words.size());
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */