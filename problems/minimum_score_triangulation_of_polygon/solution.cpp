class Solution {
public:
    int minScoreTriangulation(vector<int>& val) {
        
        int n=val.size();
        vector<vector<int>> dp(n,vector<int>(n,1e9));
        for(int sz=1;sz<n;++sz)
        {
            for(int l=0, r=sz;r<n;++r,++l)
            {
                if(sz==1)
                {dp[l][r]=0;continue;}
                if(sz == 2)
                {dp[l][r] = val[l]*val[r]*val[l+1];continue;}
                for(int k=l+1; k<r;++k)
                {
                    dp[l][r]=min(dp[l][r],val[l]*val[k]*val[r] + dp[l][k]+dp[k][r]) ;
                }
                
            }
        }
        return dp[0][n-1];
    }
};