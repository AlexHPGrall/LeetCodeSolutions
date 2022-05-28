class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for(int &n:nums)
        {++n;}
        
        for(int n:nums)
        {
            
            if(abs(n)-1<nums.size())
                nums[abs(n)-1]*=-1;
            
        }
        
        for(int i=0;i<nums.size();++i)
            if(nums[i]>=0)
                return i;
        return nums.size();
                
    }
};