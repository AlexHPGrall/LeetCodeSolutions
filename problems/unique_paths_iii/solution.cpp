class Solution {
public:
    vector<vector<int>> moves = {{1,0}, {0,1},{-1,0},{0,-1}};
    int res = 0;
    int cells =0;
    int m, n;
    void DFS(int i, int j, vector<vector<int>>& grid, int count)
    {
        grid[i][j] =-1;
        for(int k =0; k<4; ++k)
        {
            
            int ni = i+moves[k][0], nj = j + moves[k][1];
            
            if(ni >=0 && ni< m && nj >=0 && nj <n)
            {
                if(grid[ni][nj] == 2 && count == cells)
                {res++;}
                if(grid[ni][nj] ==0)
                {
                    DFS(ni, nj, grid, count + 1);
                }
            }
        }
        grid[i][j] =0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int si, sj;
        for(int i =0; i<m; ++i)
            for(int j =0; j<n; ++j)
            {
                if(grid[i][j] == 0)
                    cells++;
                if(grid[i][j] == 1)
                {si = i; sj=j;}
            }
        
        DFS(si,sj,grid,0);
        return res;
    }
};