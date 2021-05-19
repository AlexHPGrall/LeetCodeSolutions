class Solution {
public:
    int minMoves2(vector<int>& nums) {
        long n = nums.size(), minm=-1;
        for(long val : nums)
        {
            long res =0;
            for(long reval : nums)
                res+=abs(reval-val);
            if(minm ==-1)
                minm =res;
            else
                minm= min(res, minm);
        }
            
        
        return minm;
    }
};