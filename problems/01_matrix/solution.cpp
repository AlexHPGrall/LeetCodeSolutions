class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        if(mat[0][0])
            mat[0][0]=INT_MAX-1;
        for(int i=0;i<m;++i)
        {
            for(int j=0; j<n;++j)
            {
                
                if(!mat[i][j]||(i==0&&j==0))
                    continue;
                if(!i)
                    mat[i][j]=mat[i][j-1]+1;
                else if(!j)
                    mat[i][j]=mat[i-1][j]+1;
                else
                    mat[i][j]=min(mat[i-1][j],mat[i][j-1]) +1;
                if(mat[i][j]==INT_MAX)
                    mat[i][j]-=1;
            }
        }
        
        for(int i=m-1;i>=0;--i)
        {
            for(int j=n-1; j>=0;--j)
            {
                
                if(!mat[i][j]||(i==m-1&&j==n-1))
                    continue;
                if(i==m-1)
                    mat[i][j]=min(mat[i][j],mat[i][j+1]+1);
                else if(j==n-1)
                    mat[i][j]=min(mat[i+1][j]+1,mat[i][j]);
                else
                    mat[i][j]=min({mat[i][j], mat[i+1][j]+1,mat[i][j+1]+1});
            }
        }
        return mat;
    }
};