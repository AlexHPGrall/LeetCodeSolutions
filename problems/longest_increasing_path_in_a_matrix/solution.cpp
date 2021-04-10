class Solution {
public:
    int recursiveTraversal(int i, int j, int m, int n, int curr,
                           vector<vector<int>>& DPRes, vector<vector<int>>& matrix)
    {
        vector<int> max;
        int res;
        
        if(DPRes[i][j] != -1)
        {
            return curr + DPRes[i][j];
        }
        if(i + 1 < m && matrix[i+1][j]> matrix[i][j])
            max.push_back(recursiveTraversal(i+1, j, m,n, curr +1, DPRes, matrix));
        if(i -1>= 0 && matrix[i-1][j]> matrix[i][j])
            max.push_back(recursiveTraversal(i-1, j, m,n, curr +1, DPRes, matrix));
        if(j + 1 < n && matrix[i][j+1]> matrix[i][j])
            max.push_back(recursiveTraversal(i, j+1, m,n, curr +1, DPRes, matrix));
        if(j- 1 >=0 && matrix[i][j-1]> matrix[i][j])
            max.push_back(recursiveTraversal(i, j-1, m,n, curr +1, DPRes, matrix));
        res = 0;
        for(int l : max)
        {
            if(res < l)
                res =l;
        }
        if(res == 0 && curr != 0)
            res = curr;
        DPRes[i][j] = res -curr;
        return res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> DPRes(m,vector<int>(n, -1));
        int max;
        int res = 0;
        for(int i = 0; i<m; ++i)
            for(int j=0; j<n; ++j)
            {
                max=recursiveTraversal(i, j, m,n, 0, DPRes, matrix);
                if (res < max)
                    res = max;
            }
        
            
                
        return res +1;
        
        
    }
};