class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n=grid[0].size(), perimeter =0;
        for(int i=0; i<m; ++i)
        {
            for(int j =0; j<n ; ++j)
            {
                if(grid[i][j])
                {
                    perimeter = getPerimeter(i,j,m,n,grid);
                    return perimeter;
                }
            }
        }
        
        return 0;
        
    }
    
    int getPerimeter(int i, int j, int m, int n, vector<vector<int>> &grid)
    {
        if(i<0 || j<0||i>=m||j>=n||grid[i][j]==0)
            return 1;
        if(grid[i][j]  == -1)
            return 0;
        grid[i][j] = -1;
        int count =0;
        count +=getPerimeter(i+1,j,m,n,grid);
        count +=getPerimeter(i,j+1,m,n,grid);
        count +=getPerimeter(i-1,j,m,n,grid);
        count +=getPerimeter(i,j-1,m,n,grid);
        
        return count;
    }
};