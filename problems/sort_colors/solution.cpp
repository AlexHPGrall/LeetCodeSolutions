class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int l =0, r=nums.size()-1;
        for(int i=0;i<nums.size();++i)
        {
            while(l<nums.size()&&nums[l] == 0)
                ++l;
            while(~r&&nums[r] == 2)
                --r;
            if(l>i)
                i=l;
            if(i>r)
                break;
            
            if(nums[i] == 0)
            {
                nums[i] =nums[l];
                nums[l]=0;
                 if(nums[i] == 2)
            {
                nums[i] =nums[r];
                nums[r]=2;
            }
            }
            else if(nums[i] == 2)
            {
                nums[i] =nums[r];
                nums[r]=2;
                 if(nums[i] == 0)
            {
                nums[i] =nums[l];
                nums[l]=0;
                 }
            }
            
        }
    }
};