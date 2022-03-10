class Solution {
public:
    
    bool divisorGame(int n) {
        static vector<int> dp(1001,-1);
        if(dp[n]!=-1)
        {return dp[n]==1;}
        
        if(n==1)
        {dp[n]=0;return false;}
        if(n==2)
        {
            dp[n]=1;return true;
        }
        for(int x=1; x<n;++x)
        {
            if(n%x==0 && !divisorGame(n-x))
            {
                dp[n]=1;
                return true;
            }
        }
        dp[n]=0;
        return false;
    }
};