class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int notake=0;
        int take=0;
        int ptake=nums[0];
        int pnotake=0;
        int maxnotake=0;
        for(int i=1;i<nums.size();++i)
        {
            take=nums[i-1]!=nums[i]-1?(nums[i-1]==nums[i]?ptake+nums[i]:max(ptake,pnotake)+nums[i]):pnotake+nums[i];
            notake=nums[i-1]==nums[i]?pnotake:max(ptake,pnotake);
            
            ptake=take;
            pnotake=notake;   

        }
        return max(pnotake,ptake);
    }
};