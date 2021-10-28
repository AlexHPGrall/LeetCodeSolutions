class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-2; ++i)
        {
            if(i>0 && nums[i-1]==nums[i])
                continue;
            int l=i+1;
            int r=n-1;
            while(l<r)
            {
                int s=nums[i] + nums[l] +nums[r];
                if(s>0)
                {
                    r--;
                }
                else if(s<0)
                {
                    l++;
                }
                else
                {
                    while(l<r && nums[l+1]==nums[l])
                        ++l;
                    while(l<r && nums[r-1]==nums[r])
                        --r;
                    res.push_back(vector<int>{nums[i], nums[l], nums[r]});
                    ++l;
                    r--;
                }
            }
        }
        
        return res;
    }
};