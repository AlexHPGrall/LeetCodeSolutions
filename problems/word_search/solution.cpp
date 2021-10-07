class Solution {
public:
    vector<vector<bool>> vis;
    vector<vector<int>> moves ={{1,0}, {0,1}, {-1,0}, {0,-1}};
    bool DFS(vector<vector<char>>& board,int row, int col,  int index, const string &word)
    {
        //cout<<word[index]<<endl;
        if(index==word.size()-1)
            return true;
        bool res=false;
        for(int i=0; i<4;++i)
        {
            int nextRow=row+moves[i][0], nextCol=col+moves[i][1];
            if(nextRow>=0 && nextRow<board.size()&&nextCol>=0 && nextCol<board[0].size()
               &&!vis[nextRow][nextCol]&&board[nextRow][nextCol]==word[index+1])
            {
                vis[nextRow][nextCol] =true;
                res |= DFS(board,nextRow,nextCol,index+1,word);
                if(res ==true)
                    return res;
                vis[nextRow][nextCol] = false;
            }
                
            
        }
        
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(), n =board[0].size();
        vis.resize(m, vector<bool>(n, false));
        for(int i=0; i<m;++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(board[i][j] == word[0])
                {
                    vis[i][j]=true;
                    if(DFS(board,i, j,  0, word))
                        return true;
                    vis[i][j] =false;
                }
            }
        }
        
        return false;
        
    }
};