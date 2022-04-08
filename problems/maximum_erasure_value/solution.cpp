class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        
        unordered_map<int, int> vis;
        vector<int> sum(n+1, 0);
        
        int best=0;
        int curr=0;
        int start=0;
        for(int i=0; i<n;++i)
        {
            sum[i+1]=sum[i]+nums[i];
            if(vis.count(nums[i]) && start<= vis[nums[i]])
            {
                
                curr=curr - (sum[vis[nums[i]]+1]-sum[start]);
                start=vis[nums[i]]+1;
                
            }
            curr+=nums[i];
            vis[nums[i]]=i;
            best=max(best, curr);
            //cout<<curr<<endl;
        }
        return best;
        
    }
};