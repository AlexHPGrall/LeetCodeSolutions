class Solution {
public:
    int mx=1e5;
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,0);
        //sort(coins.begin(),coins.end());
        for(int i=1;i<=amount;++i)
        {
            dp[i]=mx;
            for(int c:coins)
            {
                if(i-c>=0 && dp[i-c]!=-1)
                    dp[i]=min(dp[i], 1+dp[i-c]);
            }
            if(dp[i]==mx)
                dp[i]=-1;
        }
        return dp[amount];
    }
};