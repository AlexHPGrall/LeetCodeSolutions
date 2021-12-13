class Solution {
public:
    int maxPower(string s) {
        int n = s.length();
        int p=1;
        int res=1;
        for(int i=1; i<n;++i)
        {
            if(s[i]==s[i-1])
                ++p;
            else
            {
                res = max(res,p);
                p=1;
            }
        }
        
        res= max(res,p);
        
        return res;
    }
};