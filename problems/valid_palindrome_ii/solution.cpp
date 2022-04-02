class Solution {
public:
    bool validPalindrome(string s) {
        int i=0, j=s.length()-1;
        int erri, errj;
        int err=0;
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                if(err==2)
                    return false;
                else if(err==1)
                {
                    i=erri;
                    j=errj-1;
                    ++err;
                }
                else
                {
                    err++;
                    erri=i;
                    errj=j;
                    i++;
                }
            }
            else
            {
                ++i;
                --j;
            }
        }
            
        return true;
    }
};