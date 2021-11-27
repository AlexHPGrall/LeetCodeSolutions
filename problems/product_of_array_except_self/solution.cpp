class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int lprod =1;
        int rprod =1;
        int n=nums.size();
        
        vector<int> res(n,1);
        for(int i=0;i<n;++i)
        {
            res[i] *= lprod;
            lprod*=nums[i];
            res[n-1-i] *= rprod;
            rprod*=nums[n-1-i];
        }
        
        
        return res;
    }
};