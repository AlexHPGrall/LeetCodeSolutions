class Solution {
public:
    vector<vector<int>> mv={{-1,0},{0,-1},{0,1},{1,0}};
    int surfaceArea(vector<vector<int>>& grid) {
        int n =grid.size();
        int res=0;
        for(int i=0; i<n;++i)
        {
            for(int j=0; j<n; ++j)
            {
                for(auto &v:mv)
                {
                    int ni=i+v[0], nj=j+v[1];
                    if(ni>=0 && ni <n && nj>=0 && nj<n)
                    {
                        res+=max(0, grid[i][j]-grid[ni][nj]);
                    }
                    else
                        res+=grid[i][j];
                    
                }
                if(grid[i][j])
                    res+=2;
            }
        }
        return res;
    }
};