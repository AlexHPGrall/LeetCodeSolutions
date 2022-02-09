class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,1);
        int p1=1,p2=1;
        for(int i=0,j=n-1; i<n;++i,--j)
        {
            res[i]*=p1;
            res[j]*=p2;
            p1*=nums[i];
            p2*=nums[j];
        }
        return res;
    }
};