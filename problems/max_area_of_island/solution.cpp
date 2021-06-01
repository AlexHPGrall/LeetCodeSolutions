class Solution {
public:
    int GetIslandSize(int i, int j, vector<vector<int>>& grid)
    {
        int res =1;
        int n = grid.size();
        int m = grid[0].size();
        grid[i][j] = 0;
        
        if(i>0 && grid[i-1][j] ==1)
            res +=GetIslandSize(i-1, j, grid);
        if(i+1<n && grid[i+1][j] ==1)
            res +=GetIslandSize(i+1, j, grid);
        if(j>0 && grid[i][j-1] ==1)
            res +=GetIslandSize(i, j-1, grid);
        if(j+1<m && grid[i][j+1] ==1)
            res +=GetIslandSize(i, j+1, grid);
        return res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans =0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; ++i)
        {
            for(int j = 0; j<m;++j)
            {
                if(grid[i][j] ==1)
                    ans = max(ans,GetIslandSize(i,j,grid) );
                
            }
        }
        return ans;
    }
};