class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int l=0;
        int r=-1;
        int sum=0;
        for(int n:nums)
            sum+=n;
        int res=-1;
        int curr=0;
        if(sum==x)
            return nums.size();
        while(r<(int)nums.size()-1)
        {
            ++r;
            curr+=nums[r];
            //cout<<curr<<' ';
            while(l<r&&curr>(sum-x))
            {
                curr-=nums[l];
                l++;
            }
            //cout<<curr<<endl;
            if(curr==sum-x)
                res=max(res, r-l+1);
        }
        if(res==-1)
            return res;
        return nums.size()-res;
    }
};