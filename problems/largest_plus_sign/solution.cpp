class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<uint16_t>> left(n,vector<uint16_t>(n, 1));
        vector<vector<uint16_t>> right(n,vector<uint16_t>(n, 1));
        vector<vector<uint16_t>> up(n,vector<uint16_t>(n,1));
        vector<vector<uint16_t>> down(n,vector<uint16_t>(n,1));
        for(vector<int> v: mines)
        {
            int i=v[0], j=v[1];
            left[i][j] =0;
            right[i][j] =0;
            up[i][j] =0;
            down[i][j] =0;
        }
        for(int i=1; i<n; ++i)
        {
            for(int j=1; j<n; ++j)
            {
                
                left[i][j]= left[i][j]==0?0:left[i][j-1]+1;
                up[i][j]= up[i][j]==0?0:up[i-1][j]+1;
            }
        }
        for(int i=n-2; ~i; --i)
        {
            for(int j=n-2; ~j; --j)
            {
                
                right[i][j]= right[i][j]==0?0:right[i][j+1]+1;
                down[i][j]= down[i][j]==0?0:down[i+1][j]+1;
            }
        }
        uint16_t res =0;
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                //cout<<left[i][j]<< up[i][j]<<right[i][j]<<down[i][j]<<" ";
               res=max(res,min(up[i][j],min(right[i][j], min(down[i][j],left[i][j])))); 
            }
            //cout<<endl;
        }
        return res;
        
    }
};