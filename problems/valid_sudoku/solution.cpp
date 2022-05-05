class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0; i<9;++i)
        {
            int cmask=0, rmask=0;
            for(int j=0;j<9;++j)
            {
                if(board[i][j]!='.')
                {
                    if(rmask&(1<<(board[i][j]-'0')))
                        return false;
                    rmask|=(1<<(board[i][j]-'0'));
                }
                if(board[j][i]!='.')
                {
                    if(cmask&(1<<(board[j][i]-'0')))
                        return false;
                    cmask|=(1<<(board[j][i]-'0'));
                }
                
            }
        }
        for(int i=0;i<9;i+=3)
        {
            
            for(int j=0;j<9;j+=3)
            {
                int cellMask=0;
                for(int k=0; k<3;++k)
                    for(int l=0; l<3;++l)
                    {
                        if(board[i+k][j+l]!='.')
                        {
                            if(cellMask&(1<<(board[i+k][j+l]-'0')))
                                return false;
                            cellMask|=(1<<(board[i+k][j+l]-'0'));
                        }
                    }
            }
        }
        return true;
    }
};