class Solution {
public:
    int countOrders(int n) {
        static vector<unsigned long long> dp(501,-1);
        int mod=(1e9) +7;
        if(dp[n]!=-1)
            return dp[n];
        dp[1]=1;
        for(int i=2; i<=500;++i)
        {
            dp[i]=((dp[i-1])*(i*(2*i -1)))%(mod);
        }
        return (int)(dp[n]%mod);
    }
};