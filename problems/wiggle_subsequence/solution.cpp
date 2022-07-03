class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)
            return n;
        int res=1;
        int i=1;
        int curr=nums[0];
        int prev=curr;
        while(i<n&& curr>nums[i])
        {
            curr=nums[i];
            ++i;
            res=2;
        }
        while(i<n)
        {
            prev=curr;
            while(i<n&& curr<=nums[i])
            {
                curr=nums[i];
                ++i;
            }
            if(prev!=curr)
                ++res;
            prev=curr;
            while(i<n&& curr>=nums[i])
            {
                curr=nums[i];
                ++i;
            }
            if(prev!=curr)
                ++res;

        }
        return res;
    }
};