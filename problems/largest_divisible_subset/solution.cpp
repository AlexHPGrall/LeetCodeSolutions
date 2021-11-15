class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> help(n);
        vector<int> dp(n);
        int mx=0, index=-1;
        for(int i=n-1; ~i; --i)
        {
            help[i] = i;
            dp[i] =1;
            for(int j=i+1; j<n;++j )
            {
                if(nums[j]%nums[i]==0 && dp[i]<1+dp[j])
                {
                    dp[i] = 1 + dp[j];
                    help[i] = j;    
                    
                }
            }
            if(mx<dp[i])
            {mx = dp[i]; index =i;}
        }
        vector<int> res(dp[index]);
        res[0] =nums[index];
        for(int i=1;i<res.size(); ++i)
        {
            index=help[index];
            res[i] = nums[index];
        }
        
        return res;
    }
};