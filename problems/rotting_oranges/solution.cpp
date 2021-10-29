class Solution {
public:
    struct qdata
    {
        int i;
        int j;
        int depth;
    };
    
    vector<vector<int>> moves={{1,0},{0,1},{-1,0},{0,-1}};
    int time=0;
     int m,n;
    /*
    void BFS(vector<vector<int>> &grid, int i, int j, int depth)
    {
        time = max(time, depth);
        grid[i][j]=2;
        for(vector<int> mo:moves)
        {
            int ni =i+mo[0], nj =j+mo[1];
            if(ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj] == 1)
            {
                DFS(grid,ni,nj,depth+1);
            }
        }
    }
    */
    int orangesRotting(vector<vector<int>>& grid) {
        queue<qdata> q;
        int oranges;
        m=grid.size();
        n= grid[0].size();
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(grid[i][j] == 1)
                    ++oranges;
                else if(grid[i][j] == 2)
                {
                    q.push({i,j,0});
                    grid[i][j] =3;
                }
                    
            }
        }
        while(!q.empty())
        {
            qdata d = q.front();
            q.pop();
            
            if(grid[d.i][d.j] == 2 )
                continue;
            grid[d.i][d.j] =2;
            time = max(time, d.depth);
            for(vector<int> mo:moves)
        {
            int ni =d.i+mo[0], nj =d.j+mo[1];
            if(ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj] == 1)
            {
                q.push({ni,nj,d.depth+1});
            }
        }
            
        }
        
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(grid[i][j] == 1)
                   return -1;
            }
        }
        
        return time;
        
        
    }
};
