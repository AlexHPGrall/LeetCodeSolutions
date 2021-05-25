class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n-1);
        if(n<3)
        {
            int res=0;
            for(int i:nums)
                res=max(i,res);
            return res;
                
        }
        int res=0;
        dp[0]=nums[0];
        dp[1]=max(nums[0], nums[1]);
        for(int i=2; i<n-1; ++i)
        {
            dp[i]=max(dp[i-1], nums[i]+dp[i-2]);
            
        }
        res=dp[n-2];
        dp[0]=nums[1];
        dp[1]=max(nums[2], nums[1]);
        for(int i=2; i<n-1; ++i)
        {
            dp[i]=max(dp[i-1], nums[i+1]+dp[i-2]);
        }
        return max(res, dp[n-2]);
    }
};