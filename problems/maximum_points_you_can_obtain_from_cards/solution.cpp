class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int sum=0;
        int currSum=0;
        int res=0;
        int n=nums.size();
        for(int i=0;i<n-k;++i)
        {
            sum+=nums[i];
        }
        currSum=sum;
        res=sum;
        for(int i=n-k;i<n;++i)
        {
            sum+=nums[i];
            currSum+=nums[i];
            currSum-=nums[i-(n-k)];
            res=min(res,currSum);
        }
        return sum-res;
    }
};