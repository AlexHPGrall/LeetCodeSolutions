class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        vector<int> dp(n+1, 0);
        int j=1;
        for(int i =1; i<=n; ++i)
        {
            if(j*j==i)
            {
                squares.push_back(j*j);
                ++j;
                dp[i] =1;
                continue;
            }
            int res =INT_MAX;
            for(int k=squares.size() -1; k>=0; --k)
            {
                res =min(1+dp[i-squares[k]], res);
            }
                
            dp[i] = res;
        }
        
        return dp[n];
    }
};