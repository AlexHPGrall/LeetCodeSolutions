class Solution {
public:
    int countVowelPermutation(int n) {
    vector<vector<long>> dp(n+1,vector<long>(5,0));
    int mod = 1e9+7;
    for(long &i:dp[1])
    {
        i=1;
    }
    for(int i =2; i<n+1; ++i)
    {
        dp[i][0] = (dp[i-1][1] + dp[i-1][2] +dp[i-1][4])%mod;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2])%mod;
        dp[i][2] = (dp[i-1][1] + dp[i-1][3])%mod;
        dp[i][3] = (dp[i-1][2])%mod;
        dp[i][4] = (dp[i-1][2] + dp[i-1][3])%mod;
    }
    long res=0;
        for(long i:dp[n])
        {
            res+=i%mod;
        }
    return res%mod;
    }
};