class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n));
        int up=0;
        int left=0;
        int right=n-1;
        int down=n-1;
        int curr=1;
        for(int i=0, j=0;;)
        {
            do
            {
                mat[i][j]=curr++;
                ++j;
                
                if(curr>n*n)
                    return mat;
            }while(j<right);
            
            ++up;
            
            do
            {
                mat[i][j]=curr++;
                ++i;

                if(curr>n*n)
                    return mat;
            }while(i<down);
            
            --right;
            
            do
            {
                mat[i][j]=curr++;
                --j;
                if(curr>n*n)
                    return mat;
            }while(j>left);
            
            --down;
            
            do
            {
                mat[i][j]=curr++;
                --i;
                if(curr>(n*n))
                    return mat;
            }while(i>up);
            
            ++left;
        }
        return mat;
    }
};