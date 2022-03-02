class Solution {
    const vector<vector<int>> mv={{1,0},{-1,0},{0,1},{0,-1}};
public:
    void Dfs(vector<vector<char>>& grid, int i, int j)
    {
        grid[i][j]='0';
        //cout<<i<<" "<<j<<endl;
        for(const vector<int> &v:mv)
        {
            int nr=i+v[0];
            int nc=j+v[1];
            if(~nr&& nr<grid.size()&& ~nc && nc<grid[0].size()&&grid[nr][nc]=='1')
                Dfs(grid,nr,nc);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int res=0;
        for(int i=0; i<grid.size();++i)
        {
            for(int j=0; j<grid[0].size();++j)
            {
                
                if(grid[i][j]=='1')
                {
                    res++;
                    Dfs(grid, i,j);
                }
            }
        }
        
        return res;
    }
};