class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            swap(nums1, nums2);
        
        int m=nums1.size(), n=nums2.size();
        
        bool odd = (m+n)%2;
        if(m==0)
        {
         return odd?nums2[n/2]:((double)nums2[n/2]+nums2[(n/2)-1])/2;   
        }
        if(n == 1)
            return ((double) nums1[0] + nums2[0])/2;
        int l=0, r=m;
        int size = (m+n)/2;
        if(odd)
            size++;
        int mid, mid2;
        
        while(l<r)
        {
            mid =(l+r)/2;
            mid2 = size - mid -2;
            if((mid<0 ||  mid2>= n-1 || nums1[mid] <= nums2[mid2+1]) && (mid2<0 || mid>= m-1 || nums2[mid2]<=nums1[mid+1]))
            {
                int tmp,tmp2;
                if(mid>=0)
                {
                    tmp = nums1[mid];
                    if(mid2>=0)
                        tmp = max(tmp,nums2[mid2]);
                }
                else
                    tmp = nums2[mid2];
                if(mid<m-1)
                {
                    tmp2 = nums1[mid+1];
                    if(mid2<n-1)
                        tmp2 = min(tmp2,nums2[mid2+1]);
                }
                else
                    tmp2 = nums2[mid2+1];
                 
                
                return odd?tmp:((double)(tmp+tmp2))/2;
            }
            
            
            
            if(mid>=0 && nums1[mid]>nums2[mid2+1])
            {
                r=mid;
            }
            else
            {
                l= mid +1;
            }
        }
        if(l == r && l==0)
        {
            mid =-1;
            mid2=size-1;
            int tmp2;
             if(mid<m-1)
                {
                    tmp2 = nums1[mid+1];
                    if(mid2<n-1)
                        tmp2 = min(tmp2,nums2[mid2+1]);
                }
                else
                    tmp2 = nums2[mid2+1];
            return odd?nums2[mid2]:((double)(nums2[mid2]+tmp2))/2;
        }
        return -1;
    }
};