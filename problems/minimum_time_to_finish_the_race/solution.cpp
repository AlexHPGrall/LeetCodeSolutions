class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int c, int n) {
    vector<long long> dp(n+1,INT_MAX);
        dp[0]=0;
        for(vector<int> &T:tires)
        {
            long long curr=T[0];
            long long acc=T[0];
            for(int i=1;i<=n;++i)
            {
                dp[i]=min(dp[i],curr);
                acc*=T[1];
                curr+=acc;
                if(curr>1e9)
                    break;
            }
        }
        
        for(int i=2; i<=n;++i)
        {
            for(int j=1;j<i;++j)
            {
                dp[i]=min(dp[i], dp[j]+dp[i-j]+c);
            }
        }
        return dp[n];
    }
};