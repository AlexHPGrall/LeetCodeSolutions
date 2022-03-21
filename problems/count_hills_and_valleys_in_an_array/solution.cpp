class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int i=0;
        int count=0;
        int n=nums.size();
        while(i<n && nums[i]==nums[0])
        {
            ++i;
        }
        while(i<n)
        {
            int j=i+1;
            while(j<n && nums[j]==nums[i])
                ++j;
            if(j<n)
            {
                if(nums[i-1]<nums[i]&&nums[j]<nums[i])
                    count++;
                else if(nums[i-1]>nums[i] && nums[j]>nums[i])
                    count++;
            }
            i=j;
        }
        return count;
    }
};