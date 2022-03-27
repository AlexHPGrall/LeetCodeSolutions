class Solution {
public:
    long long getPal(int n, int l)
    {
        if(l==1)
        {
            return n;
        }
        if(l==2)
        {
            return n*10+n;
        }
        int t=l;
        int acc=0;
        while(t>2)
        {
            acc*=10;
            acc+=9;
            t-=2;
        }
        n+=acc;
        int i=0;
        long long res=n;
        if(l&1)
        {
            n/=10;
            
        }
        while(n)
        {
            res*=10;
            res+=n%10;
            n/=10;
        }
        return res;
        
    }
    vector<long long> kthPalindrome(vector<int>& q, int intLength) {
        int n=q.size();
        vector<long long> res(n);
        int maxP=1;
        for(int i=intLength;i>2;i-=2)
        {
            maxP*=10;
        }
        maxP*=9;
        
        for(int i=0;i<n;++i)
        {
            if(q[i]>maxP)
                res[i]=-1;
            else
                res[i]=getPal(q[i],intLength);
                       
        }
        return res;
    }
};