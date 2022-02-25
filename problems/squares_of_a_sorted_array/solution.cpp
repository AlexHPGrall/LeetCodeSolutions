class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int mid=0;
        int n=nums.size();
        for(int i=0; i<n; ++i)
        {
            if(nums[i]<0)
                mid++;
            nums[i]*=nums[i];
        }
        
        if(mid==0)
        {
            return nums;
        }
        if(mid==n)
        {
            reverse(nums.begin(), nums.end());
            return nums;
        }
        int l=mid-1;
        int r=mid;
        vector<int> res(n);
        int i=0;
        while(i<n)
        {
            if(l>-1 && r<n)
            {
                if(nums[r]>nums[l])
                {
                    res[i]=nums[l];
                    l--;
                }
                else
                {
                    res[i]=nums[r];
                    r++;
                }
            }
            else if(r<n)
            {
                res[i]=nums[r];
                ++r;
            }
            else
            {
                res[i]=nums[l];
                --l;
            }
            ++i;
            
        }
        return res;
    }
};