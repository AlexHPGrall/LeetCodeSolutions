class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int>&nums, int i)
    {
        if(i==nums.size())
        {
            res.push_back(nums);
        }
        int mask=0;
        for(int j=i;j<nums.size();++j)
        {
            if(mask&(1<<(nums[j]+10)))
                continue;
            mask |=(1<<(nums[j]+10));
            swap(nums[i], nums[j]);
            dfs(nums, i+1);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        dfs(nums,0);
        return res;
    }
};