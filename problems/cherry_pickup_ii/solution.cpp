class Solution {
public:
    vector<int> mv={-1,0,1};
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int res=0;
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n, vector<int>(n,0)));
        dp[0][0][n-1]=grid[0][0]+grid[0][n-1];
        for(int r=1; r<m;++r)
        {
            for(int i=0;i<min(r+1,n-1);++i)
                for(int j=max(i+1, n-r-1);j<n;++j)
                {
                    int tmp=0;
                    for(int k=0;k<3;++k)
                    {
                        for(int l=0;l<3;++l)
                        {
                            int pi=i+mv[k];
                            int pj=j+mv[l];
                            if(pi>=0&& pi<min(r,n-1) && pj>=max(pi+1, n-r-2) && pj<n)
                            {
                                tmp=max(tmp, dp[r-1][pi][pj]+grid[r][i]+grid[r][j]);
                            }
                        }
                    }
                    dp[r][i][j]=tmp;
                    res=max(res, dp[r][i][j]);
                    
                }
            
            
        }
        
        return res;
    }
};