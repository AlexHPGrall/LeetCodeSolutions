class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int res=0;
        int r=-1,c=-1;
        for(int i=0; i<8; ++i)
        {
            for(int j=0; j<8;++j)
            {
                if(board[i][j]=='R')
                {
                    c=j;
                    r=i;
                    break;
                }
            }
            if(r!=-1)
                break;
        }
        
        for(int i=r, j=c; i>=0 && board[i][j]!='B' ;--i)
            if(board[i][j]=='p')
            {res++; break;}
        for(int i=r, j=c; i<8 && board[i][j]!='B' ;++i)
            if(board[i][j]=='p')
                {res++; break;}
        for(int i=r, j=c; j>=0 && board[i][j]!='B' ;--j)
            if(board[i][j]=='p')
                {res++; break;}
        for(int i=r, j=c; j<8 && board[i][j]!='B' ;++j)
            if(board[i][j]=='p')
                {res++; break;}
        return res;
    }
};