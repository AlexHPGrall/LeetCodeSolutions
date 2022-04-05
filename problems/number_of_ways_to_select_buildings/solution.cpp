class Solution {
public:
    long long numberOfWays(string s) {
        int n=s.size();
        vector<int> z(n,0), o(n,0);
        int ocnt=0,zcnt=0;
        
        for(int i=0; i<n;++i)
        {
            if(i>0)
            {z[i]=z[i-1];
            o[i]=o[i-1];}
            if(s[i]=='0')
            {
                zcnt++;
                z[i]+=1;
            }
            else
            {
                ocnt++;
                o[i]+=1;
            }
            
        }
        
        long long res=0;
        for(int i=1;i<n-1;++i)
        {
            if(s[i]=='0')
            {
                res+=o[i]*(ocnt-o[i]);
            }
            else
            {
                res+=z[i]*(zcnt-z[i]);
            }
        }
        return res;
    }
};