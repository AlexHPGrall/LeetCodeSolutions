class Solution {
public:
    int mod = 1e9 + 7;
    int numTilings(int n) {
        static int dp[1001];
        if(dp[n] != 0)
            return dp[n];
        if(n==0 || n==1)
        {
            dp[n] =1;
            return 1;
        }
        if(n==2)
        {
            dp[n]=2;
            return 2;
        }
        
        dp[n] = ((2*numTilings(n-1))%mod + numTilings(n-3))%mod;
        return dp[n];
        
    }
};