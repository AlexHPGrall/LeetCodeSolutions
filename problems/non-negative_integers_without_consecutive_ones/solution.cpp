class Solution {
public:
    int findIntegers(int n) {
        if(n==0)
            return 1;
        if(n==1)
        {
            return 2;
        }
        if(n==2 || n==3)
        {
            return 3;
        }
        int res =0;
        int k=0;
        int dp[32];
        dp[0] = 1;
        dp[1] = 2;
        while((1<<k) <= n)
        {k++;}
        
        k--;
        cout<<k;
        for(int i=2; i<=k;++i)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        res +=dp[k];
        
        
        
            if(n&(1<<(k-1)))
            {
                res += dp[k-1] -1;
            }
            
            else
            {
                res+= findIntegers(n%(1<<k)) -1;
            }
        
        
        return res+1;
    }
};