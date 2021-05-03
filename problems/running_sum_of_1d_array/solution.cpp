class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> sum(nums.size());
        int n =  nums.size();
        sum[0] = nums[0];
        for(int i =1; i<n; ++i)
            sum[i] = sum[i-1] + nums[i];
        return sum;
    }
};