class NumMatrix {
    vector<vector<int>> num;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        num = matrix;
        int m = matrix.size(), n = matrix[0].size();
        for(int i=0;i<m; ++i)
        {
            for(int j=1; j<n; ++j)
            {
                num[i][j] +=num[i][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res=0;
        for(int i=row1; i<=row2; ++i)
        {
            res+=num[i][col2];
            if(col1)
                res-=num[i][col1-1];
        }
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */