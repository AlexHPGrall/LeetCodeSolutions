class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int med;
        if(n&1)
            med=nums[n/2];
        else
            med=nums[(n/2)-1]+(nums[n/2]-nums[(n/2)-1])/2;
        int res=0;
        for(int num:nums)
            res+=abs(num-med);
        return res;
    }
};