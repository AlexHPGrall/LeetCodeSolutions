class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<uint32_t> dp(target+1);
        dp[0] =1;
        for(int curTarget = 1; curTarget<=target; ++curTarget)
        for(const auto &i:nums)
            if(i<=curTarget)
                dp[curTarget] += dp[curTarget-i];
        return dp[target];
        
    }
};