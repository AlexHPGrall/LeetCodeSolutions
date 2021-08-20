class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    int colrow[9];
    int cell[9];
        
    memset(colrow, 0, 9*4);
    memset(cell, 0, 9*4);
        
    for(int i=0;i<9;++i)
        for(int j=0; j<9;++j)
        {
            if(board[i][j]=='.')
                continue;
            int row = 1<<(board[i][j]-'1');
            int col =  1<<(board[i][j]-'1' +9);
            if(colrow[i]&row)
                return false;
            else
                colrow[i] |= row;
            
            if(colrow[j]&col)
                return false;
            else
                colrow[j] |= col;
            
            if(cell[(j/3) + (i/3)*3]&row)
                return false;
            else
                cell[(j/3) + (i/3)*3] |= row;
                
        }
        
        return true;
    }
};