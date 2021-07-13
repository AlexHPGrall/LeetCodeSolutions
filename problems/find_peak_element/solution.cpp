class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 0;
        if(nums[1] < nums[0])
            return 0;
        if(nums[n-2]<nums[n-1])
            return n-1;
        
        int left=0, right = n-1;
        while(left<right)
        {
            int mid =(left+right)/2;
            if(nums[mid-1]<nums[mid] && nums[mid+1]<nums[mid])
            {
                return mid;
            }
            if(nums[mid-1]<nums[mid] && nums[mid]<nums[mid+1])
            {
                left = mid+1;
            }
            else
            {
                right =mid;
            }
        }
        return -1;
    }
};