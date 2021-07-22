class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
       
        int n=nums.size();
         vector<int> mi(n), ma(n);
        ma[0]= nums[0];
        for(int i =1; i<n;++i)
        {
            ma[i]=max(ma[i-1], nums[i]);
        }
        mi[n-1] = nums[n-1];
        for(int i=n-2; ~i; --i)
        {
            mi[i] = min(mi[i+1], nums[i]);
        }
        for(int i =0; i<=n-2; ++i)
        {
            if(ma[i]<=mi[i+1])
                return i+1;
        }
        
        return 1;
        
    }
};