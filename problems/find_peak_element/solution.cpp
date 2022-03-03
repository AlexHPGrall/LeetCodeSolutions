class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        if(nums.size()==2)
        {
            if(nums[0]>nums[1])
                return 0;
            else
                return 1;
        }
        int l=0;
        int r=nums.size();
        while(l<r)
        {
            int mid=l+(r-l)/2;
            if(mid==0)
            {
                if(nums[0]>nums[1])
                return 0;
                else
                return 1;
            }
            if(mid==nums.size()-1)
            {
                if(nums[mid]>nums[mid-1])
                return mid;
                else
                return mid-1;
            }
            if(nums[mid-1]<nums[mid]&&nums[mid+1]<nums[mid])
            {
                return mid;
            }
            if(nums[mid]<nums[mid+1])
            {
                l=mid+1;
            }
            else
            {
                r=mid;
            }
        }
        return l;
    }
};