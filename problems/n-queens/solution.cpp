class Solution {
public:
     vector<vector<string>> res;
    void dfs(vector<string> &curr, int n, int row, int c, int d1, int d2)
    {
        if(row==n)
            res.push_back(curr);
        for(int col=0; col<n;++col)
        {
            if(((1<<col)&c) || (1<<(row-col+n)&d1) || (1<<(row+col)&d2))
                continue;
            curr[row][col]='Q';
            dfs(curr, n, row+1, c|(1<<col), d1|(1<<(row-col+n)), d2|(1<<(row+col)));
            curr[row][col]='.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string s(n, '.');
        vector<string> curr(n, s);
        dfs(curr, n, 0, 0, 0, 0);
        return res;
        
    }
};