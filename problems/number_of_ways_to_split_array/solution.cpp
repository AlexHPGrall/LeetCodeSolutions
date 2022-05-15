class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long> sum(n,0);
        sum[0]=nums[0];
        int res=0;
        for(int i=1;i<n;++i)
        {
            sum[i]=nums[i]+sum[i-1];
        }
        sum[n-1]=nums[n-1];
        if(sum[n-2]>=sum[n-1])
            res++;
        for(int i=n-2;i>0;--i)
        {
            sum[i]=sum[i+1]+nums[i];
            if(sum[i-1]>=sum[i])
                res++;
        }
        return res;
        
    }
};