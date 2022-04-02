class Solution {
public:
    int numSteps(string s) {
        int n=s.length();
        int i=n-1;
        int res=0;
        while(i>0)
        {
            if(s[i]=='0')
            {++res;--i;}
            else
            {
                res++;
                while(i>=0&&s[i]=='1')
                {
                    res++;
                    --i;
                }
                if(i>0)
                    s[i]='1';
                
                    
            }
            
        }
        return res;
    }
};