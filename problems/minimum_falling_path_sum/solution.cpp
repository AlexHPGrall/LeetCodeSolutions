class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if(n==1)
            return matrix[0][0];
        int res=INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        for(int j=0; j<n;++j)
            dp[n-1][j]=matrix[n-1][j];
        for(int i=n-1; i>0;--i)
        {
            for(int j=0; j<n;++j)
            {
                
                for(int k=-1;k<2;++k)
                {
                    
                    int nj=j+k;
                    if(nj>=0 && nj<n)
                    {
                        
                        dp[i-1][j]=min(dp[i-1][j], dp[i][nj]+matrix[i-1][j]);
                    }
                }
                if(i==1)
                    res=min(res,dp[i-1][j]);
                //cout<<res<<' '<<dp[i-1][j]<<endl;
            }
        }
        return res;
    }
};