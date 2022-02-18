class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                int k=i, l=j;
                while(k>0 && l>0 && mat[k][l]<mat[k-1][l-1])
                {
                    swap(mat[k][l],mat[k-1][l-1]);
                    --k;--l;
                }
            }
        }
        
        return mat;
    }
};