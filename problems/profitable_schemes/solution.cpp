#define ull unsigned long long
class Solution {
public:
    const int mod =(1e9)+7;
    vector<vector<vector<unsigned long long>>> dp;
    ull rec(int n, int minp, vector<int> &grp, vector<int> &p, int currp, int index )
    {
        if(index==grp.size() && currp>=minp )
        {return 1;}
        if(index==grp.size())
            return 0;
        if(dp[n][index][currp]!=-1)
            return dp[n][index][currp];
        unsigned long long tres=0;
        if(grp[index] <=n)
            tres+=rec(n-grp[index], minp, grp, p, min(currp+p[index],minp), index+1)%mod;
        tres+=rec(n,minp,grp,p,currp,index+1)%mod;
        dp[n][index][currp]=tres%mod;
        return dp[n][index][currp];
        
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        dp.resize(n+1, vector<vector<ull>>(group.size(),vector<ull>(minProfit+1,-1)));
        return rec(n, minProfit, group, profit,0, 0)%mod;
        
    }
};