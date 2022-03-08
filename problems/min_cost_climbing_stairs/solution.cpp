class Solution {
public:
    vector<int> dp;
    int RecTrav(int step, vector<int> &cost)
    {
        if(step ==1 || step==0)
            return 0;
        if(dp[step]!=-1)
            return dp[step];
        dp[step]=min(RecTrav(step-1,cost)+cost[step-1], RecTrav(step-2,cost)+cost[step-2]);
        return dp[step];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n =cost.size();
        dp.resize(n+1, -1);
        return RecTrav(n,cost);
        
    }
};