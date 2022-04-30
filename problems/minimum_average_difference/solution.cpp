class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int> pref(n), suff(n);
        long long  psum=0, ssum=0;
        for(int i=0; i<n;++i)
        {
            psum+=nums[i];
            suff[n-1-i]=ssum/(max(i,1));
            ssum+=nums[n-1-i];
            pref[i]=psum/(i+1);
        }
        int currMin=INT_MAX;
        int res;
        for(int i=0; i<n; ++i)
            if(abs(pref[i]-suff[i])<currMin)
            {
                currMin=abs(pref[i]-suff[i]);
                res=i;
            }
        return res;
    }
};