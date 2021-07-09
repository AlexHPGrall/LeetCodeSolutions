class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res=1;
        int n = nums.size();
        vector<int> dp(n,1);
        for(int i=n-2; i>=0; --i)
        {
            int j=i;
            while(++j<n)
            {
                if(nums[i]<nums[j])
                {
                    dp[i] = max(dp[i],1+dp[j]);
                    
                    
                }
                res=max(res, dp[i]);
            }
        }
        return res;
        
    }
};