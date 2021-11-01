class Solution {
public:
    vector<vector<int>> moves={{1,0}, {0,1}, {-1,0}, {0,-1}};
    int m,n;
    void DFS(int i, int j, vector<vector<char>>& board)
    {
        board[i][j]='I';
        for(int k =0; k<4;++k)
        {
            int ni = i+moves[k][0], nj=j+moves[k][1];
            if(ni>=0 && ni<m && nj>=0 && nj<n && board[ni][nj] == 'O')
                DFS(ni, nj, board);
        }
    }
    void solve(vector<vector<char>>& board) {
        m=board.size();
        n=board[0].size();
        
        for(int j=0;j<n;++j)
        {
            if(board[0][j] == 'O')
            {
                DFS(0,j, board);
            }
            if(board[m-1][j] == 'O')
            {
                DFS(m-1,j, board);
            }
        }
        for(int i=0;i<m;++i )
        {
            if(board[i][0] == 'O')
            {
                DFS(i,0, board);
            }
            if(board[i][n-1] == 'O')
            {
                DFS(i,n-1, board);
            }
        }
        for(int i =0; i<m;  ++i)
        {
            for(int j= 0; j<n;++j)
            {
                if(board[i][j] == 'O')
                    board[i][j]='X';
                if(board[i][j]=='I')
                    board[i][j] ='O';
            }
        }
    }
};