class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int cur=0;
        int mask=(1<<(maximumBit))-1;
        for(int n:nums)
        {
         cur^=n;   
        }
        vector<int> res;
        for(int i=nums.size()-1;i>=0;--i)
        {
            int k=(~(cur))&mask;
            res.push_back(k);
            cur^=nums[i];
        }
        return res;
    }
};