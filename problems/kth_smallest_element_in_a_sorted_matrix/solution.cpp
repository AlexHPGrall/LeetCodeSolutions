class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n=matrix.size();
        int m =min(n,k);
        int left = matrix[0][0];
        int right = matrix[m-1][m-1];
        
        while(left<right)
        {
            int mid = (left+right)/2;
            int j=m-1;
            int count=0;
            for(int i =0; i<m; ++i)
            {
                while(j>=0 && matrix[i][j]>mid )
                    --j;
                count += j+1;
            }
            if(count<k)
            {
                left=mid+1;
            }
            else{
                right =mid;
            }
        }
        return left;
        
    }
};