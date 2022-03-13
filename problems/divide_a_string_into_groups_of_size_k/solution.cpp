class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        int i=0;
        int n=s.length();
        string tmp(k,fill);
        while(i<n)
        {
            for(int j=0;j<k;++j)
            {
                if(i<n)
                {
                    tmp[j]=s[i];
                    ++i;
                }
                else
                {
                    tmp[j]=fill;
                }
                
            }
            res.push_back(tmp);
        }
        return res;
    }
};