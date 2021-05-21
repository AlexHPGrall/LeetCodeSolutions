class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int n = pattern.size();
        vector<string>res;
        for(string const& s: words)
        {
            unordered_map<char, char> p2w;
            int i=0;
            while(i<n)
            {
                if(p2w.find(pattern[i]) == p2w.end() )
                {
                    int check= 0;
                for(auto it:p2w)
                {
                    if(it.second == s[i])
                             ++check;
                        
                        if(check)
                            break;
                    }
                    if(check)
                            break;
                       
                
                    p2w[pattern[i]] = s[i];
                    
                    
                }
                else if(p2w[pattern[i]] != s[i] )
                {break;}
                
                
                
                ++i;
            }
            cout<<endl;
            if(i==n)
                res.push_back(s);
        }
        return res;
    }
};