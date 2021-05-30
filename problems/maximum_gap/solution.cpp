class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n<2)
            return 0;
        int maxel = nums[0], minel=nums[0];
        
        for(int i:nums)
        {
            maxel = max(i, maxel);
            minel = min(i, minel);
        }
        int range = max((maxel-minel)/(n-1),1);
        vector<vector<int>> buckets((maxel-minel)/range +1);
        for(int i: nums)
        {
           
            buckets[(i-minel)/range].push_back(i);
        }
        int prevmax=minel;
        int res=0;
        for(auto& bucket:buckets)
        {
            if(bucket.empty())
                continue;
            minel =maxel =bucket[0];
            for(int i:bucket)
            {
                maxel = max(i, maxel);
                minel = min(i, minel);
            }
            res = max(minel - prevmax, res);
            prevmax = maxel;
        }
        return res;
    }
};