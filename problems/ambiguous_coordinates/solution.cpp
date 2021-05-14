class Solution {
public:
    
    bool IsValid(int i, int k, int l, int n, string &s)
    {
        if(s[1] == '0' && i!=1 && k!=1)
            return false;
        if(s[i+1] == '0' && i!=n-3 && l!= i+1)
            return false;
        
        if(k!=0 && s[i]=='0')
            return false;
        if(l!= i && s[n-2] == '0')
            return false;
        
        return true;
    }
    
        vector<string> ambiguousCoordinates(string s) {
        vector<string> res;
        int n = s.length();
        
        for(int i = 1; i<n-2; ++i)
        {
            
            for(int k=0; k<i; ++k)
            {
                for(int l =i; l<n-2;++l)
                {
                    if(!IsValid(i ,k,l,n,s))
                        continue;
                    string out;
                    out.push_back('(');
                    for(int j = 1; j<n-1; ++j)
                    {
                        
                        out.push_back(s[j]);
                        if(j==i)
                        {
                            out.push_back(',');
                            out.push_back(' ');
                        }
                        else if(j==k || j==l)
                        {
                            out.push_back('.');
                        }
                    }
                    out.push_back(')');
                    res.push_back(out);
                }
                
            }
            
        }
        return res;
    }
};