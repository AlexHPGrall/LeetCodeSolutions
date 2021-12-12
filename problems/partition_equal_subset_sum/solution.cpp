class Solution {
public:
    
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum =0;
        for(int u:nums)
            sum+=u;
        if(sum%2 ==1)
            return false;
        if(nums[n-1] == sum/2)
            return true;
        sum/=2;
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
        
        for(int i=1; i<=n; ++i)
        {
            for(int j=1; j<=sum; ++j)
            {
                if(nums[i-1] == j)
                    dp[i][j] =true;
                else if(nums[i-1]>j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j]= dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
        }
        
        
        return dp[n][sum];
        
    }
};