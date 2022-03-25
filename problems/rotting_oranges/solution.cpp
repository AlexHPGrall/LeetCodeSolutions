class Solution {
public:
    vector<vector<int>> moves={{1,0},{0,1},{-1,0},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0; i<grid.size(); ++i)
            for(int j=0; j<grid[0].size();++j)
                if(grid[i][j]==2)
                    q.push({i,j});
        int time=0;
        
        while(!q.empty())
        {
            int count=q.size();
            while(count--)
            {
                pair<int, int> p=q.front();
                q.pop();
                int r=p.first;
                int c=p.second;
                //cout<<r<<' '<<c<<endl;
                for(auto &mv:moves)
                {
                    int nr=r+mv[0];
                    int nc=c+mv[1];
                    if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1)
                    {
                        grid[nr][nc]=2;
                        q.push({nr,nc});
                    }
                }
                
                
            }
            ++time;
        }
        for(int i=0; i<grid.size(); ++i)
            for(int j=0; j<grid[0].size();++j)
                if(grid[i][j]==1)
                    return -1;
        return max(0,time-1);
    }
};