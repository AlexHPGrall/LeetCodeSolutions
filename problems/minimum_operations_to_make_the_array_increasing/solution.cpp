class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res=0;
        int cur=nums[0];
        for(int i=1;i<nums.size();++i)
        {
            if(nums[i]<=cur)
            {res+=cur-nums[i]+1;
             cur++;}
            else
                cur=nums[i];
        }
        return res;
    }
};