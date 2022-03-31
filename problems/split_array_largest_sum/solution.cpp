class Solution {
public:
    
    bool isPossible(vector<int>&nums ,int m, int k,int n)
    {
        int currsum=0;
        for(int i=0;i<n;++i)
        {
            if(currsum+nums[i]>k)
            {
                m--;
                currsum=nums[i];
                if(m<=0)
                    return false;
                    
            }
            else
                currsum+=nums[i];
        }
        return true;
    }
    int splitArray(vector<int>& nums, int m) {
        int n=nums.size();

        int sum=0;
        int maxEl=INT_MIN;
        for(int i=0;i<n;++i)
        {sum+=nums[i];maxEl=max(maxEl, nums[i]);}
        
        int l=maxEl;
        int r=sum;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(isPossible(nums,m,mid,n))
                r=mid-1;
            else
                l=mid+1;
        }
        return l;
    }
};