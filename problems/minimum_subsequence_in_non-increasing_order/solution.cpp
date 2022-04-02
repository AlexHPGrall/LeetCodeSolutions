class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int sum =0;
        int n=nums.size();
        vector<int> res;
        for(int i:nums)
            sum+=i;
        sort(nums.rbegin(),nums.rend());
        int currsum=0;
        int i=0;
        while(currsum<=sum && i<nums.size())
        {
            currsum+=nums[i];
            sum-=nums[i];
            res.push_back(nums[i]);
            ++i;
        }
        return res;
    }
};