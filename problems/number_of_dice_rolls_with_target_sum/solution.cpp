class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<unsigned long long>> dp(n+1, vector<unsigned long long>(target+1,0));
        int mod= (1e9)+7;
        for(int i=1; i<=min(k,target); ++i)
        {
            dp[1][i]=1;
        }
        
        for(int i=2;i<=n;++i)
        {
            for(int t=1;t<=target;++t)
            {
                for(int j=1;j<=k;++j)
                {
                    if(t-j>0)
                        dp[i][t] +=(dp[i-1][t-j]);     
                }
                dp[i][t]=dp[i][t]%mod;
            }
        }
        
        return (int)(dp[n][target]%mod);
    }
};