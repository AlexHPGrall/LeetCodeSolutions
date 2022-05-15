class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s=to_string(num);
        unsigned long long cur=0;
        int res=0;
        unsigned long long tenPow=1;
        for(int i=0;i<k;++i)
        {cur=cur*10+(s[i]-'0');tenPow*=10;}
        tenPow/=10;
        if(cur&&!(num%cur))
            res++;
        
        for(int i=k;i<s.size();++i)
        {
            cur=cur - tenPow*(s[i-k]-'0');
            cur=cur*10+(s[i]-'0');
            if(cur &&!(num%cur))
                res++;
            //cout<<cur<<endl;
        }
        return res;
    }
};