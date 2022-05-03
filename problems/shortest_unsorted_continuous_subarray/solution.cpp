class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int mn=nums[n-1];
        int mx=nums[0];
        vector<int> minArr(n), maxArr(n);
        maxArr[0]=mx;minArr[n-1]=mn;
        for(int i=1; i<n;++i)
        {
            mx=max(mx, nums[i]);
            mn=min(mn, nums[n-1-i]);
            maxArr[i]=mx;
            minArr[n-1-i]=mn;
        }
        int l=-1;
        if(minArr[0]>=nums[0])
        {
            l=0;
            while(l<n-1 &&nums[l+1]<=minArr[l+1]&&nums[l]<=nums[l+1])
                ++l;
        }
        if(l==n-1)
            return 0;
        int r=n;
        if(maxArr[n-1]<=nums[n-1])
        {
            r=n-1;
            while(r>0 &&nums[r-1]>=maxArr[r-1]&&nums[r]>=nums[r-1])
                --r;
        }
        if(l==-1 && r==n)
            return n;
        return r-(l+1);
    }
};