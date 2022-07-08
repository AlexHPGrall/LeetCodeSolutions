class Solution {
public:
    int mx=1e7;

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int dp[101][21][101]={};
        for(int i=0;i<=m;++i)
        {
            for(int j=1;j<=n;++j)
            {
                for(int k=0; k<=m;++k)
                {
                    
                    if(k>i || (k==0 && i>0))
                    {   
                        dp[i][j][k]=mx;
                        continue;
                    }
                    if(i==0)
                        continue;
                    dp[i][j][k]=mx;
                    if(houses[i-1]!=0)
                    {   
                        if(houses[i-1]==j)
                        {
                            dp[i][j][k]=dp[i-1][j][k];
                            for(int l=1;l<=n;++l)
                            {
                                if(l==j)
                                    continue;
                                dp[i][j][k]=min(dp[i][j][k], dp[i-1][l][k-1]);
                            }
                                
                        }
                        continue;
                    }
                    for(int l=1;l<=n;++l)
                    {
                        if(l!=j)
                            dp[i][j][k]=min(dp[i][j][k], cost[i-1][j-1]+dp[i-1][l][k-1]);
                        else
                            dp[i][j][k]=min(dp[i][j][k], cost[i-1][j-1]+dp[i-1][l][k]);
                    }
                }
            }
        }
        int res=mx;
        for(int j=1;j<=n;++j)
            res=min(res,dp[m][j][target]);
        return res>=mx?-1:res;
    }
};