class NumMatrix {
    vector<vector<int>> matSum;
    int m;
    int n;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        n=matrix[0].size();
        m=matrix.size();
        matSum.resize(m+1,vector<int>(n+1));
        for(int i=0;i<m;++i)
        {
            for(int j=0; j<n;++j)
            {
                matSum[i+1][j+1]=matrix[i][j] + matSum[i][j+1] + matSum[i+1][j] -matSum[i][j] ;
            }
            
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res=matSum[row2+1][col2+1]-matSum[row1][col2+1]-matSum[row2+1][col1]+matSum[row1][col1];
        return res;
    }
};
/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */