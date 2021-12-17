class Solution {
public:
    int maximalSquare(vector<vector<char>>& M) {
        int m=M.size();
        int n=M[0].size();
        int res=0;
        vector<vector<int>> dp(m, vector<int>(n));
        for(int i=0; i<m;++i)
        {
            for(int j=0; j<n;++j)
            {
                if(i==0 || j==0)
                {
                    res=max(res,M[i][j]-'0');
                    dp[i][j]=M[i][j]-'0';
                    continue;
                }
                if(M[i][j] == '1')
                {
                    dp[i][j] = min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]}) +1;
                    res=max(res,dp[i][j]);
                }
                else
                    dp[i][j]==0;
            }
        }
        
        return res*res;
    }
};