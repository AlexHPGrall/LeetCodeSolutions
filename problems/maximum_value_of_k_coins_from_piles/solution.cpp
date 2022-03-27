class Solution {
public:
    int recTrav(int i, int k, vector<vector<int>> &piles, vector<vector<int>> &dp,vector<vector<int>> &memo)
    {
        //cout<<i<<' '<<k<<endl;
        if(i>=piles.size())
            return 0;
        if(memo[i][k]!=-1)
            return memo[i][k];
        
        int res=0;
        for(int p=0; p<=min(k,(int)piles[i].size()); ++p)
        {
            res=max(res, dp[i][p] +recTrav(i+1, k-p, piles,dp,memo) );
        }
        
        memo[i][k]=res;
        return res;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
       int n=piles.size();
        vector<vector<int>> dp(n, vector<int>(k+1,0));
        vector<vector<int>> memo(n, vector<int>(k+1,-1));
        
        for(int i=0; i<n;++i)
        {
            for(int j=0;j<min(k,(int)piles[i].size());++j)
                dp[i][j+1]=dp[i][j]+piles[i][j];
        }
        
        return recTrav(0,k,piles, dp, memo);
    }
};