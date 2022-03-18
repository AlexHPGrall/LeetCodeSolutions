class Solution {
public:
    vector<vector<int>> moves = {{-1,0},{1,0},{0,-1},{0,1}};
    int orangesRotting(vector<vector<int>>& grid) {
     queue<pair<int,int>> q;
        int m =grid.size();
        int n=grid[0].size();
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(grid[i][j]==2)
                q.push({i,j});
        }
    }
        int time=0;
        while(!q.empty())
        {
            int cnt=q.size();
            while(cnt--)
            {
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                for(auto &mv:moves)
                {
                    int ni = i+mv[0];
                    int nj=j+mv[1];
                    if(ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj]==1)
                    {
                        grid[ni][nj]=2;
                        q.push({ni,nj});
                    }
                }
            }
            ++time;
        }
            for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(grid[i][j]==1)
                return -1;
        }
    }
        return max(0,time-1);
    }
};