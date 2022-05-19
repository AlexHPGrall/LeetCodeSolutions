class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> moves={{-1,0},{1,0},{0,-1},{0,1}};
    int Dfs(int i, int j, vector<vector<int>> &grid)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
        int res=1;
        for(auto &mv:moves)
        {
            int ni=i+mv[0];
            int nj=j+mv[1];
            if(ni>=0 && ni<grid.size() && nj>=0 && nj<grid[0].size() && grid[ni][nj]>grid[i][j])
                res=max(res, 1+Dfs(ni,nj,grid));
        }
        dp[i][j]=res;
        return res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        dp.resize(m,vector<int>(n,-1));
        int res=1;
        for(int i=0;i<m;++i)
        {
            for(int j=0; j<n;++j)
            {
                res=max(res, Dfs(i,j,matrix));
            }
        }
        return res;
    }
};