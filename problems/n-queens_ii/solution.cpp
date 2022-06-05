class Solution {
public:
    int dfs(int n, int row, int c, int d1, int d2)
    {
        if(row==n)
            return 1;
        int res=0;
        for(int col=0; col<n;++col)
        {
            if(((1<<col)&c) || (1<<(row-col+n)&d1) || (1<<(row+col)&d2))
                continue;
            res+=dfs( n, row+1, c|(1<<col), d1|(1<<(row-col+n)), d2|(1<<(row+col)));
        }
        return res;
    }
    int totalNQueens(int n) {
        
        return dfs(n, 0, 0, 0, 0);

        
    }
};