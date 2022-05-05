class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0;
        int j=nums.size()-1;
        while(i<j)
        {
            if(nums[j]==target-nums[i])
                return {i+1,j+1};
            else if(nums[j]>target-nums[i])
                --j;
            else
                ++i;
        }
        return {};
    }
};