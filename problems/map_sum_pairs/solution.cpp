struct TrieNode
{
    TrieNode *Children[26];
    int sum;
};


class MapSum {
public:
    /** Initialize your data structure here. */
    TrieNode *root;
    unordered_map<string,int> mp;
    MapSum() {
        root = new TrieNode();
        
    }
    
    void insert(string key, int val) {
        TrieNode *cur = root;
        bool change =false;
        if(mp.find(key) != mp.end())
            change=true;
        else
            mp[key] =val;
        int valo = change?(val-mp[key]):val;
        mp[key] = val;
        int i=0, n=key.length();
        char c = key[i];
        root->sum += valo;
            while(cur->Children[c-'a'] != nullptr)
            {
                cur = cur->Children[c-'a'];
                cur->sum += valo;
               
                ++i;
                if(i<n)
                c = key[i];
                else
                    break;
            }
           
             
                while(i<n)
                {
                    c = key[i];
                    TrieNode *Next=new TrieNode();
                    Next->sum=val;
                    cur->Children[c-'a']=Next;
                    cur =Next;
                    ++i;
                    
                }
                
            
        
        }
    
    
    int sum(string prefix) {
        TrieNode *cur = root;
        int i=0, n=prefix.length();
        char c = prefix[i];
        while(i<n)
        {
            c=prefix[i];
            if(cur->Children[c-'a'] == nullptr)
                return 0;
           
            cur= cur->Children[c-'a'];
            
            
            
            ++i;
        }
        
        return cur->sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */