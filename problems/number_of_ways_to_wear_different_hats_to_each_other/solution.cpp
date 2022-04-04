class Solution {
public:
    #define ull unsigned long long
    unordered_map<int,unordered_map<int, ull>> dp;
    int mod=(1e9)+7;
    int n;
    int match[10][41]={0};
    ull Dfs(vector<vector<int>>& hats, int h, int picked)
    {
        
        if(picked ==(1<<n)-1)
            return 1;
        if(h==41)
            return 0;
        if(dp[h].count(picked))
            return dp[h][picked]%mod;
        ull res=0;
        for(int i=0; i<n;++i)
        {
            
            if(!(picked&(1<<i)) && match[i][h])
            {
                
                picked|=(1<<i);
                res+=(Dfs(hats, h+1, picked))%mod;
                res=res%mod;
                picked&=~(1<<i);
            }
        }
        res+=(Dfs(hats, h+1, picked))%mod;
                res=res%mod;
        dp[h][picked]=res%mod;
        return res%mod;
    }
    int numberWays(vector<vector<int>>& hats) {
        n=hats.size();
        int sh=40, eh=1;
        for(int i=0; i<n;++i)
        {
            for(int h:hats[i])
            {
                sh=min(sh,h);
                eh=max(sh,h);
                match[i][h]=1;
            }
        }
        
            return (int) (Dfs(hats,1,0)%mod);
    }
};