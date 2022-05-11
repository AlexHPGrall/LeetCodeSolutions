class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int n, int i, int vi)
    {
        
        if(i==n)
            return 1;
        //if(dp[i][vi]!=-1)
            //return dp[i][vi];
        int res=0;
        res=dfs(n,i+1,vi);
        if(vi<4)
            res+=dfs(n,i,vi+1);
        //dp[i][vi]=res;
        return res;
    }
    int countVowelStrings(int n) {
        dp.resize(n, vector<int>(5,-1));
        return dfs(n, 0,0);
    }
};