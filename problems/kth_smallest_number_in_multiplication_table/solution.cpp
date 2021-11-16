class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1;
        int right = m*n;
        
        while(left<right)
        {
            int mid = (left+right)/2;
            int j=n;
            int count=0;
            for(int i =1; i<=m; ++i)
            {
                while(j>=1 && i*j >mid )
                    --j;
                count += j;
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