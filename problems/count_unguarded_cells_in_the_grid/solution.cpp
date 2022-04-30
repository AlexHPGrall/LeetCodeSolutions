class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> grid(m, vector<char>(n,'0'));
        for(auto &w:walls)
        {
            grid[w[0]][w[1]]='w';
        }
        for(auto &g:guards)
        {
            grid[g[0]][g[1]]='g';
        }
        for(auto &g:guards)
        {
            int i=g[0], j=g[1];
            i++;
            while(i<m && grid[i][j]!='w' && grid[i][j]!='g')
            {grid[i][j]='1';++i;}
            i=g[0]-1;
            while(i>=0 && grid[i][j]!='w' && grid[i][j]!='g')
            {grid[i][j]='1';--i;}
            i=g[0];
            ++j;
            while(j<n && grid[i][j]!='w' && grid[i][j]!='g')
            {grid[i][j]='1'; ++j;}
            j=g[1]-1;
            while(j>=0 && grid[i][j]!='w' && grid[i][j]!='g')
            {grid[i][j]='1'; --j;}
        }
        //cout<<"ok"<<endl;
        int res=0;
        for(int i=0; i<m; ++i)
            for(int j=0; j<n;++j)
                if(grid[i][j]=='0')
                    res++;
        return res;
    }       
};