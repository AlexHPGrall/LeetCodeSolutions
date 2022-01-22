class Solution {
public:
    bool winnerSquareGame(int n) {
        static vector<char> dp(1e5+1,2);
        if(dp[n]!=2)
            return dp[n];
        dp[1]=1;
        dp[2]=0;
        
        for(int i=3; i<=1e5;++i)
        {
            for(int j=1; j*j<=i;++j)
            {
                if(j*j==i)
                {
                    dp[i]=1;
                    break;
                }
                if(dp[i-(j*j)]==0)
                {
                    dp[i]=1;
                    break;
                }
            }
            if(dp[i]==2)
                dp[i]=0;
        }
        
        return dp[n];
        
    }
};