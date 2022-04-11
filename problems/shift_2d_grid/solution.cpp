class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        k=k%(m*n);
        vector<int> tmp(m*n);
        for(int i=0; i<m;++i)
            for(int j=0; j<n;++j)
            {
                tmp[i*n +j]=grid[i][j];
            }
        for(int i=0; i<m;++i)
            for(int j=0; j<n;++j)
            {
                grid[i][j]=tmp[((m*n-k) + (i*n +j))%(m*n)];
            }
        return grid;
    }
};