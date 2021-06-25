class Solution {
public:
    const int mod = 1e9 + 7, moves[4][2] {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        uint dp[51][51][51]{};
        auto outOfBounds= [&](int i, int j){return (i<0 || j<0 || i>=m || j >=n);};
        for(int M =1; M<=maxMove; ++M)
        {
            for(int i=0; i<m;++i)
            {
                for(int j = 0; j<n; ++j)
                {
                    for(int k=0; k<4; ++k)
                    {
                        if(outOfBounds(i+moves[k][0], j+moves[k][1]))
                            dp[i][j][M]++;
                        else
                            dp[i][j][M] += dp[i + moves[k][0]][j + moves[k][1]][M-1] % mod;
                    }
                        
                }
            }
                
        }
        return dp[startRow][startColumn][maxMove] % mod;
    }
};