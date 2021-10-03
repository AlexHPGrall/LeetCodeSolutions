class Solution {
public:
    bool canJump(vector<int>& nums) {
        int target = nums.size()-1;
        for(int i=nums.size()-2; ~i; --i)
        {
            if(nums[i]+i>=target)
                target=i;
        }
        
        
        return (target ==0);
    }
};