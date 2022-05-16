class Solution {
public:
    vector<vector<int>> moves={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0])
            return -1;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        queue<pair<int, int>> q;
        q.push({0,0});
        vis[0][0]=1;
        int dist=1;
        while(!q.empty())
        {
            int cnt=q.size();
            while(cnt--)
            {
                auto [i,j]=q.front();
                q.pop();
                if(i==m-1&&j==n-1)
                    return dist;
                for(auto &mv:moves)
                {
                    int ni=i+mv[0];
                    int nj=j+mv[1];
                    if(ni>=0 && ni<m && nj>=0 && nj<n && !vis[ni][nj]&&!grid[ni][nj])
                    {
                        vis[ni][nj]=1;
                        q.push({ni,nj});
                    }
                }
            }
            dist++;
        }
        return -1;
    }
};