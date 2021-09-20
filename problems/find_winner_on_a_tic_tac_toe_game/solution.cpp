
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
      int board[9];
        for(int i=0;i<8;++i)
            board[i]=0;
      for(int i =0; i<moves.size(); i++)
      {
          int row =moves[i][0], col =moves[i][1];
         if(i%2 ==0)
         {
              
              board[row*3 +col] =1;
        }
        else
        {
          board[row*3 +col] =-1;  
        }
          
      }
        for(int i=0; i<3; ++i)
        {
            if( board[i*3]&& (board[i*3 +0] == board[i*3 +1] && board[i*3 +1] == board[i*3 +2]))
            {
                if(board[i*3] == 1)
                    return "A";
                else
                    return "B";
            }
        }
        for(int i=0; i<3; ++i)
        {
            if( board[i] && (board[0+i] == board[3 +i] && board[3 +i] == board[6 +i]))
            {
                if(board[i] == 1)
                    return "A";
                else
                    return "B";
            }
        }
        if( board[0] && (board[0] == board[4] && board[4] == board[8]))
            {
                if(board[0] == 1)
                    return "A";
                else
                    return "B";
            }
        if( board[2] && (board[2] == board[4] && board[4] == board[6]))
            {
                if(board[2] == 1)
                    return "A";
                else
                    return "B";
            }
        if(moves.size() == 9)
               return "Draw";
               
        return "Pending";
    }
};