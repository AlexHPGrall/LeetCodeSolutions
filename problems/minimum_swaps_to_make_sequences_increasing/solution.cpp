class Solution {
public:

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int swp=1, noswp=0;
        for(int i=1;i<n;++i)
        {
            int tswp=n,tnoswp=n;
            if(nums1[i]>nums1[i-1] && nums2[i]>nums2[i-1])
            {
                tnoswp=noswp;
                tswp=swp+1;
            }
            if(nums2[i]>nums1[i-1]&&nums1[i]>nums2[i-1])
            {
                tswp=min(noswp+1,tswp);
                tnoswp=min(swp,tnoswp);
            }
            swp=tswp;
            noswp=tnoswp;
        }
         return min(swp,noswp);   
    }
};