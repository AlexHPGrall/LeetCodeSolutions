class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0;
        int j=0;
        int n=nums.size();
        while(i<n && j<n)
        {
            while(j<n-1&&nums[i]%2!=0)
            {
                ++j;
                swap(nums[i],nums[j]);
            }
            ++i;
            if(j<i)
                j=i;
        }
        return nums;
    }
};