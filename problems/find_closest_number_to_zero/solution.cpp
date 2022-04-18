class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int res=nums[0];
        for(int n:nums)
        {
            if(abs(n)<abs(res))
                res=n;
            else if(abs(n) == abs(res) && n>res)
                res=n;
        }
        return res;
    }
};