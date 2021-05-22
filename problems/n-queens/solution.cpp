class Solution {
public:
    void solve(int row ,int n, vector<string> &board, vector<vector<string>> &res)
    {
        if(row ==n)
        {
            res.push_back(board);
            return;
        }
        for(int i = 0; i<n; ++i)
        {
            if(check(row, i, n, board))
            {
                board[row][i]='Q';
                solve(row+1, n, board, res);
                board[row][i]='.';
            }
            
            
        }
    }
    bool check(int row, int col, int n, vector<string> &board)
    {
        for(int i= row-1; i>=0; --i)
        {
            if(board[i][col] == 'Q')
                return false;
            if(col+(row-i)<n && board[i][col+(row-i)] == 'Q')
                return false;
            if(col-(row-i)>=0 && board[i][col-(row-i)] == 'Q')
                return false;
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        string s(n, '.');
        vector<string> board(n, s);
        solve(0,n,board,res);
        
       
        
        return res;
        
    }
};