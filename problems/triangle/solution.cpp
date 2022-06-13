class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        if(n==1)
            return triangle[0][0];
        vector<int> dp1(n), dp2(n);
        dp1[0]=triangle[0][0];
        int res=INT_MAX;
        for(int i=1;i<n;++i)
        {
            for(int j=0;j<=i;++j)
            {
                if(j==i)
                {
                    dp2[j]=dp1[j-1];
                }
                else if(j==0)
                {
                    dp2[j]=dp1[j];
                }
                else
                    dp2[j]=min(dp1[j], dp1[j-1]);
                dp2[j]+=triangle[i][j];
                if(i==n-1)
                {
                    res=min(res, dp2[j]);
                }
            }
            swap(dp1,dp2);
        }

        return res;
        
    }
};