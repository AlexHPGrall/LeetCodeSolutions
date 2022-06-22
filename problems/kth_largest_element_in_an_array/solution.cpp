class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l=0;
        int r=nums.size()-1;
        k=nums.size()-k;
        while(l<r)
        {
            int pivotIndex =l+(rand()%(r+1-l));
            swap(nums[pivotIndex],nums[r]);
            int i=l-1;
            for(int j=l;j<r;++j)
            {
                if(nums[j]<nums[r])
                {
                    ++i;
                    swap(nums[j],nums[i]);
                }
            }
            ++i;
            swap(nums[i],nums[r]);
            if(i==k)
                return nums[i];
            if(i<k)
            {
                l=i+1;
            }
            else
            {
                r=i-1;
            }
        }
        return nums[l];
    }
};