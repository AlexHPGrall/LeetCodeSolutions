class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int res =0;
        int n = nums.size();
        int i=0;
        while(++i <n)
        {
            if(nums[i] < nums[i-1])
            {
                int lres =0;
                res++;
                if(res >1)
                    return false;
                if(i>1)
                {
                    if(nums[i]<nums[i-2])
                        lres++;
                }
                if(i != n-1)
                {
                    if(nums[i+1] < nums[i-1])
                    lres++;
                }
                
                if(lres >=2)
                    return false;
                
            }           
        }
        return true;
    }
};