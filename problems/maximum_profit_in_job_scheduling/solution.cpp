class Solution {
public:
    vector<int> dp;
    int Dfs(int i, vector<int>& start, vector<int>& end, vector<int>& profit)
    {
        if(i==start.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        
        int ni=distance(start.begin(), lower_bound(start.begin(), start.end(),end[i]));
        //cout<<i<<' '<<ni<<endl;
        dp[i]=max(Dfs(i+1,start,end,profit),profit[i]+Dfs(ni,start,end,profit));
        return dp[i];
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        dp.resize(startTime.size(),-1);
        vector<pair<int, pair<int, int>>> v;
        for(int i=0; i<startTime.size();++i)
            v.push_back({startTime[i],{endTime[i],profit[i]}});
        sort(v.begin(), v.end());
        for(int i=0; i<startTime.size();++i)
        {
            startTime[i]=v[i].first;
            endTime[i]=v[i].second.first;
            profit[i]=v[i].second.second;
        }
        return Dfs(0, startTime, endTime, profit);
    }
};