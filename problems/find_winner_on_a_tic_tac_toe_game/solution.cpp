class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
       vector<vector<int>> grid(3, vector<int>(3,0));
        int curr=1;
        for(auto &m:moves)
        {
            grid[m[0]][m[1]] = curr;
            curr*=-1;
        }
        for(int i=0;i<3;++i)
        {
            int row=grid[i][0]+grid[i][1]+grid[i][2];
            
            int col=grid[0][i]+grid[1][i]+grid[2][i];
            if(row==3||col ==3)
                return "A";
            if(col==-3 || row==-3)
                return "B";
        }
        int diag1=grid[0][0]+grid[1][1]+grid[2][2];

        int diag2=grid[2][0]+grid[1][1]+grid[0][2];
        if(diag1==3 || diag2==3)
            return "A";
        if(diag1 == -3 || diag2 ==-3)
            return "B";
        if(moves.size()==9)
        return "Draw";
        return "Pending";
    }
};