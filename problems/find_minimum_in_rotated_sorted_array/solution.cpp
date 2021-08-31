class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int left=0, right=n-1;
        if(n==1)
            return nums[0];
        if(n==2)
            return min(nums[0], nums[1]);
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(nums[left]>nums[left+1])
                return nums[left+1];
            if(nums[mid]>nums[mid+1])
                return nums[mid+1];
            if( nums[mid-1]>nums[mid])
                return nums[mid];
            
            if(nums[left]<nums[mid] && nums[mid]<nums[right])
                return nums[left];
            
            if(nums[left]>nums[mid])
                right =mid-1;
            else
                left=mid+1;
        }
        return nums[0];
    }
};