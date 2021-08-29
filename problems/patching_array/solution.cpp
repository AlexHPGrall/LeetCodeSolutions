class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int ans=0;
        int i=0;
        uint64_t curr =nums[0]==1?++i:0;
        while(curr<n && i<nums.size())
        {
            if(nums[i]<=curr)
            {
                curr+=nums[i];
                ++i;
            }
            else
            {
                if(nums[i]==curr+1)
                  ++i;
                else
                    ans++;
                
                    
                curr+=curr+1;
                
            }
            
        }
        while(i>=nums.size() && curr<n)
        {
            curr+=curr+1;
            ans++;
        }
        return ans;
    }
};