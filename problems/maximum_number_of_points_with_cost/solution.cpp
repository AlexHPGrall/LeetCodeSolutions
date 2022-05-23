class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m=points.size();
        int n=points[0].size();
        vector<vector<long long>> dp(m,vector<long long>(n,0));
        for(int i=0; i<n;++i)
        {
            dp[0][i]=points[0][i];
        }
        for(int i=1;i<m;++i)
        {
            
            for(int j=0, s=0; j<n;++j)
            {
                if(dp[i-1][j]>=dp[i-1][s]+s-j)
                    s=j;
                dp[i][j]=dp[i-1][s]+s-j;
            }
            for(int j=n-1, s=n-1; j>=0;--j)
            {
                if(dp[i-1][j]>=dp[i-1][s]+j-s)
                    s=j;
                dp[i][j]=points[i][j]+max(dp[i][j],dp[i-1][s]+j-s);
            }
        }
        long long res=0;
        for(int i=0; i<n;++i)
        {
            res=max(dp[m-1][i],res);
        }
        return res;
    }
};