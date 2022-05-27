class Solution {
public:
    int mod=(1e9)+7;
    int Dp[5001][7][16]={};
    int Dfs(int n, int prev, int cnt, vector<int>& rollMax)
    {
        if(n==0)
        {
            return 1;
        }
        if(Dp[n][prev][cnt]!=0)
            return Dp[n][prev][cnt]%mod;
        int res=0;
        for(int i=1;i<=6;++i)
        {
            if(i==prev)
            {
                if(cnt==rollMax[i-1])
                    continue;
               
                res=(res+Dfs(n-1, i, cnt+1, rollMax)%mod)%mod;
            }
            else
            {
                res=(res+ Dfs(n-1,i,1,rollMax)%mod)%mod;
            }
        }
        Dp[n][prev][cnt]=res%mod;
        return res%mod;
        
    }
    int dieSimulator(int n, vector<int>& rollMax) {
        return (Dfs(n, 0,0,rollMax))%mod;
    }
};