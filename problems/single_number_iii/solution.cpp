class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int64_t xxx=nums[0];
        for(int i =1; i<nums.size(); ++i)
        {
            xxx ^= nums[i];
        }
        int64_t rmst = xxx & ~(xxx-1);
        int x =0,y=0;
        for(int i=0; i<nums.size(); ++i)
        {
            if(nums[i] & rmst)
                x^=nums[i];
            else
                y^=nums[i];
        }
        
        return {x,y};
    }
};