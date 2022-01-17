class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> mp;
        unordered_map<string,char> rmap;
        int i=0;
        int n=s.size();
        for(char c:pattern)
        {
            if(i>=n)
                return false;
            if(mp.count(c))
            {
                int start=i;
                while(i<n && s[i] != ' ')
                {
                    if(s[i]!=mp[c][i-start])
                    {
                        return false;
                    }
                    ++i;
                }
            }
            else
            {
                while(i<n && s[i] != ' ')
                {
                    mp[c].push_back(s[i]);
                    ++i;
                }
                if(rmap.count(mp[c]))
                    return false;
                rmap[mp[c]] = c;
                    
            }
            ++i;
            
        }
        
        if(i<n)
            return false;
        
        return true;
    }
};