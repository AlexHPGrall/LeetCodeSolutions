class Solution {
public:
    int mx=1e7;
    int dp[101][21][101]={};
    int Dfs(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target, int i, int nei)
    {
        if(nei>target)
            return mx;
        if(i==houses.size())
        {
            if(nei+1==target)
              return 0;
            else 
                return mx;
        }
        if(houses[i]!=0)
        {
            if(i>0 && houses[i-1]!=houses[i])
                return Dfs(houses, cost, m, n, target, i+1, nei+1);
            else
            {
                return Dfs(houses, cost, m, n, target, i+1, nei);
            }
        }
        if(i>0 &&dp[i][houses[i-1]][nei]!=0)
            return dp[i][houses[i-1]][nei];
        int res=mx;
        for(int j=1;j<=n;++j)
        {
            houses[i]=j;
            if(i>0 && houses[i-1]!=houses[i])
                res=min(res, cost[i][j-1]+Dfs(houses, cost, m,n,target, i+1, nei+1));
            else
                res=min(res, cost[i][j-1]+Dfs(houses, cost, m,n,target, i+1, nei));
            houses[i]=0;
        }
        if(i>0)
            dp[i][houses[i-1]][nei]=res;
        return res;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int res=Dfs(houses, cost, m,n,target,0,0);
        
        return res>=mx?-1:res;
    }
};