class Solution {
public:
    vector<int> cnt={0,0,3,3,3,3,3,4,3,4};
    int mod=(1e9)+7;
    int Dfs(string &d, int index, vector<int> &dp)
    {

        if(index==d.size())
        {
            return 1;
        }
        if(dp[index]!=-1)
            return dp[index];
        int res=0;
        for(int i=1; i<=cnt[d[index]-'0'];++i)
        {
            if(index+i>d.size() || (d[index+i-1]!=d[index]))
               break;
            res=(res%mod)+(Dfs(d, index+i,dp)%mod);
        }
        dp[index]=res%mod;
        return res%mod;
    }
    int countTexts(string pressedKeys) {
        vector<int> dp(pressedKeys.size(), -1);
        return Dfs(pressedKeys, 0,dp);
        
    }
};