class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m= matrix.size();
        int n = matrix[0].size();
        
        int res = -2e5;
        for(int i =0; i<m; ++i)
            for(int j =0; j<n; ++j)
            {
                
                if(matrix[i][j]<=k)
                {
                    res = max(res, matrix[i][j]);
                    if(res == k)
                        return k;
                }
                
                if(j>0)
                    matrix[i][j] += matrix[i][j-1];
                if(i>0)
                    matrix[i][j] += matrix[i-1][j];
                if(i>0 && j>0)
                    matrix[i][j] -=matrix[i-1][j-1];
                if(matrix[i][j]<=k)
                {
                    res = max(res, matrix[i][j]);
                    if(res == k)
                        return k;
                }
                
            }
        for(int i =0; i<m; ++i)
            for(int j =0; j<n; ++j)
                for(int h =0; h<=i; ++h)
                    for(int l=0; l<=j; ++l)
                    {
                        if((i == h && j == l )||( h==0 && l == 0))
                           continue;
                        int test;
                       
                        
                         
                        if(h==0)
                            test = matrix[i][j] - matrix[i][l-1];
                        else if(l==0)
                            test=  matrix[i][j] - matrix[h-1][j];
                        else
                            test = matrix[i][j] - matrix[h-1][j]-matrix[i][l-1] + matrix[h-1][l-1];
                        
                        if(test >k)
                            continue;
                        
                        res = max(res, test);
                        if(res ==k)
                            return k;
                    }
        return res;
    }
};