class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n= mat[0].size();
        if(r*c != n*m)
            return mat;
        vector<vector<int>> res(r, vector<int>(c));
        int i=0, j=0;
        for(int k=0; k<r; ++k)
        {
            
            vector<int> row(c);
            for(int l=0; l<c; ++l)
            {
                
                row[l]=mat[i][j];
                if(++j==n)
                {
                    j=0;
                    ++i;
                }
            }
            res[k]=row;
        }
        
        return res;
        
    }
};