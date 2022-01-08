class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,0)));
        for(int i=0; i<n;++i)
        {
            for(int j=0; j<n;++j)
            {
                if(i==j)
                    dp[m-1][i][j]=grid[m-1][i];
                else
                    dp[m-1][i][j]=grid[m-1][i] + grid[m-1][j];
            }   
        }
        for(int i = m-2; ~i; --i)
            for(int j = 0; j<n; ++j)
                for(int k=0;k<n;++k)
                {
                    int temp=-1;
                    for(int p=-1;p<2;++p)
                        for(int q=-1;q<2;++q)
                        {
                            if(j+p<n && j+p>=0 && k+q<n && k+q >=0)
                                temp=max(temp, dp[i+1][j+p][k+q]);
                        }
                    dp[i][j][k]=temp;
                    if(k==j)
                        dp[i][j][k]+=grid[i][j];
                    else
                        dp[i][j][k]+=grid[i][j] + grid[i][k];
                    
                }
        return dp[0][0][n-1];
    }
};