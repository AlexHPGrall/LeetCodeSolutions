class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<3)
            return 0;
        int res=0;
        int n=2;
        int currdiff=nums[1]-nums[0];
        for(int i=2; i<nums.size(); ++i)
        {
            
            if(nums[i]-nums[i-1]==currdiff)
            {
                n++;
            }
            else
            {
                if(n>=3)
                    res+=((n*(n+1))/2)-(n+n-1);
                n=2;
                currdiff=nums[i]-nums[i-1];
            }
        }
        if(n>=3)
            res+=((n*(n+1))/2)-(n+n-1);

        return res;
    }
};