class Solution {
public:
    vector<vector<int>> moves= {{0,1},{1,0},{0,-1},{-1,0}};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m =grid.size(), n=grid[0].size();
        queue<tuple<int,int,int,int>> q;
        q.push({0,0,k,0});
        
        vector<vector<int>> vis(m, vector<int>(n, -1));
        vis[0][0]=k;
        //cout<<m<<" "<<n<<endl;
        while(!q.empty())
        {
            auto [x, y,r,s] =q.front();
            q.pop();
            
             //cout<<x<<" "<<y<<" "<<r<<endl;
            if(x== m-1 && y==n-1)
                return s;
            
            
            for(int i =0;i<4;++i)
            {
               
                
                int nx= x+moves[i][0], ny =y+moves[i][1];
                
                if(nx>=0 && nx<m && ny>=0 && ny<n)
                {
                    
                    if(!grid[nx][ny] && (vis[nx][ny]<r))
                    {
                        vis[nx][ny]=r;
                        q.push({nx,ny,r,s+1});
                    }
                        
                    else if(r>0 && grid[nx][ny] ==1 && (vis[nx][ny]<r-1) )
                    {
                        vis[nx][ny]=r-1;
                        q.push({nx, ny, r-1, s+1});
                        
                    }
                        
                }
            }
            
        }
        
        return -1;
            
    }
};