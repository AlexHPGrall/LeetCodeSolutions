class Solution {
public:
    int n, moves[4][2] {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int swimInWater(vector<vector<int>>& grid) {
        n= grid.size();
        int l= 2*(n-1), r= n*n-1, mid;
        bool visited[50][50] = {};
        while(l<=r)
        {
            mid  = (l+r)/2;
            if(path(grid, 0,0,mid,visited))
                r=mid-1;
            else
                l=mid +1;
            
            memset(visited, false, sizeof visited);  
        }
        return l;
        
            
    }
    
    bool path(vector<vector<int>>& grid, int i, int j, int max, bool vis[][50])
    {
        if(i<0 || i>=n|| j<0 || j>=n || grid[i][j] > max || vis[i][j])
            return false;
        if(i == n-1 && j == n-1)
            return true;
        vis[i][j] =true;
        for(int mv = 0; mv <4; ++mv)
            if(path(grid, i+moves[mv][0], j+moves[mv][1], max, vis))
                return true;
        return false;
    }
};