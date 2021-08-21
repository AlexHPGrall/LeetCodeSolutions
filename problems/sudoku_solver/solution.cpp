class Solution {
public:
     bool isValid(int i,int j,vector<vector<char>>&board){
        for(int k=0;k<9;k++){
            if(k!=i and board[k][j]==board[i][j]){
                return false;
            }
        }
        for(int k=0;k<9;k++){
            if(k!=j and board[i][k]==board[i][j]){
                return false;
            }
        }
        int i1=(i/3)*3,j1=(j/3)*3;
        for(int k=i1;k<i1+3;k++){
            for(int l=j1;l<j1+3;l++){
                if((k!=i and l!=j) and board[k][l]==board[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValidUtill(vector<vector<char>>& board,int i,int j){
        if(i>=9){
            return true;
        }
        if(j==9){
            return isValidUtill(board,i+1,0);
        }
        if(board[i][j]!='.'){
            return isValidUtill(board,i,j+1);
        }
        
        for(int k=1;k<=9;k++){
            board[i][j]='0'+k;
            if(isValid(i,j,board) and isValidUtill(board,i,j+1)){
                return true;
            }
            board[i][j]='.';
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        isValidUtill(board,0,0);
    }
};