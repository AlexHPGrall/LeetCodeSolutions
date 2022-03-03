class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int j=0;
        for(int i=1;i<s.length();++i)
        {
            j=0;
            int k=i;
            if(i>s.length()/2)
                return false;
            if(s.length()%(i)!=0)
                continue;
            while(i<s.length() && s[i]==s[j])
            {
                ++i;
                ++j;
            }
            if(i==s.length())
                return true;
            if(j!=0)
                i=k;
            
        }
        return false;
    }
};