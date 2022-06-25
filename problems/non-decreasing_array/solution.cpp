class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n=nums.size();
        bool found=false;
        for(int i=0;i<n-1;++i)
        {
            if(nums[i]>nums[i+1])
            {
                if(found)
                    return false;
                if(i>0 && i<n-2)
                {
                    if(nums[i-1]>nums[i+2])
                        return false;
                    if((nums[i]<=nums[i+2]) || (nums[i-1]<=nums[i+1] && nums[i+1]<=nums[i+2]))
                        ++i;
                    else
                        return false;
                }
                found=true;
            }
        }
        return true;
    }
};