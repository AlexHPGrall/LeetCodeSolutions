class Solution {
public:
    int balancedStringSplit(string s) {
        int r=0,l=0,res=0;
        for(char c:s)
        {
            if(c=='R')
                ++r;
            if(c=='L')
                ++l;
            if(l==r)
            {
                l=0;
                r=0;
                res++;
            }
        }
        return res;
    }
};