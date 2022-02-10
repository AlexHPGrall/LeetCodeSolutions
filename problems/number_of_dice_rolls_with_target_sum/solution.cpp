class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int mod=1e9+7;
        vector<vector<int>> dp(n+1,vector<int>(target+1, 0));
        
        for(int j = 1;j<=target;++j)
        {
            for(int i= 1; i<=n;++i)
            {
                if(i*k<j)
                    continue;
                if(i==1)
                {
                    dp[i][j]=1;
                    continue;
                }
                    
                for(int a=1; a<=k; ++a)
                {
                    if(j>a)
                        dp[i][j]= dp[i][j]%mod + dp[i-1][j-a]%mod;
                }
            }
        }
       return dp[n][target]%mod;
    }
};