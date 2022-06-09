class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int curr=nums[0];
        int res=1;
        for(int i=1;i<nums.size();++i)
        {
            if(nums[i]-curr>k)
            {
                curr=nums[i];
                ++res;
            }
        }
        return res;
    }
};