class Solution {
public:
    int endMask;
    int dp[1<<14][16] = {}; 
    int dfs(int mask, int sesh, vector<int> &tasks, int curr)
    {
        if(mask==endMask)
            return 0;
        if(dp[mask][curr]!=-1)
            return dp[mask][curr];
        int res=INT_MAX;
        for(int i=0; i<tasks.size(); ++i)
        {
            if(mask&(1<<i))
                continue;
            if(curr+tasks[i]<=sesh)
                res=min(res, dfs(mask|(1<<i),sesh,tasks, curr+tasks[i]));
            else
                res=min(res, 1+dfs(mask|(1<<i),sesh, tasks, tasks[i]));
        }
        dp[mask][curr]=res;
        return res;
    }
        
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n=tasks.size();
        endMask=(1<<n)-1;
        memset(dp, -1, sizeof(dp));
        return 1+dfs(0, sessionTime, tasks, 0);
    }
};