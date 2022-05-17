class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int l=k;
        int res=0;
        while(j<nums.size())
        {
            if(nums[j]==1 || l>0 )
            {
                if(!nums[j])
                    l=max(0,l-1);
                j++;
                res=max(res,j-i);
            }
            else if(nums[j]==0 && l==0)
            {
                if(nums[i]==0)
                    l=min(l+1, k);
                if(i==j)
                    ++j;
                ++i;
            }
            
        }
        return res;
    }
};