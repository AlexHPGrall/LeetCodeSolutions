class Solution {
public:
    unordered_map<int, unordered_map<int,pair<int,int>>> dp;
    pair<int,int> Dfs(int rem, int mask, vector<int> &alice)
    {
        if(rem==0)
            return {0,mask};
        if(dp[rem].count(mask))
            return dp[rem][mask];
        pair<int,int> res={0,mask};
        //cout<<mask<<endl;
        for(int i=1; i<12; ++i)
        {
            pair<int, int> tmp;
            if(((1<<i)&mask)==0 && alice[i]<rem)
            {
                tmp=Dfs(rem-1-alice[i],mask|(1<<i),alice);
                if(tmp.first+i>res.first)
                    res={tmp.first+i,tmp.second};
            }
        }
        dp[rem][mask]=res;
        return res;
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> res(12,0);
        pair<int,int> p=Dfs(numArrows, 0, aliceArrows);
        int sum=0;
        for(int i=1; i<12;++i)
        {
            
            if((1<<i)&p.second)
                res[i]=aliceArrows[i]+1;
            sum +=res[i];
        }
        res[0]=numArrows-sum;
        return res;
    }
};