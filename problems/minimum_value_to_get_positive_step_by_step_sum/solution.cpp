class Solution {
public:
    int minStartValue(vector<int>& nums) {
       int res=INT_MAX;
        int sum=0;
        for(int n:nums)
        {
            sum+=n;
            if(sum<res)
                res= sum;
        }
        
        return res<0?(-res +1):1;
    }
};