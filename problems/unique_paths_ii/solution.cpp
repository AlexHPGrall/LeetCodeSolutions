class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n= obstacleGrid[0].size();
        if(m==1 && n ==1)
            return !obstacleGrid[0][0]?1:0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        dp[0][0] =!obstacleGrid[0][0]?1:0;
        for(int i = 1; i<n; ++i)
        {
            if(!obstacleGrid[0][i])
                dp[0][i] = dp[0][i-1];
            else
                dp[0][i] = 0;
        }
        for(int j = 1; j<m; ++j)
        {
            if(!obstacleGrid[j][0])
                dp[j][0] = dp[j-1][0];
            else
                dp[j][0] = 0;
        }
        for(int j =1; j<m; ++j)
        {
            for(int i =1; i<n; ++i)
            {
                if(!obstacleGrid[j][i])
                dp[j][i] = dp[j-1][i] + dp[j][i-1];
                else
                dp[j][i] = 0;
            }
        }
        return dp[m-1][n-1];
    }
};