class Solution {
    vector<vector<int>> moves={{-1,-1}, {-1,0}, {-1, 1}, {0,-1},{0,1},{1,-1},{1,0},{1,1}};
    int countNeighbors(vector<vector<int>> &grid, int i, int j)
    {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        for(vector<int> &mv:moves)
        {
            int ni=i+mv[0];
            int nj=j+mv[1];
            if(ni>=0 && ni<m && nj>=0 && nj <n && grid[ni][nj]>=1)
                 count++;
        }
        return count;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n =board[0].size();
        for(int i=0; i<m;++i)
        {
            for(int j=0; j<n;++j)
            {
                int c=countNeighbors(board, i,j);
                if(board[i][j]==1)
                    board[i][j]+=c;
                else
                    board[i][j]-=c;
            }
        }
        for(int i=0; i<m;++i)
        {
            for(int j=0; j<n;++j)
            {
               switch(board[i][j])
               {
                   case -3: 
                   case 3:
                   case 4:
                       board[i][j]=1;
                       break;
                   default:
                       board[i][j]=0;
               }
            }
        }
        
    }
};