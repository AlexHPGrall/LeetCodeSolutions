class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1)
        {
            if(k%2==1)
                return -1;
            else 
                return nums[0];
        }
        int currmax=INT_MIN;
        for(int i=0; i<n;++i)
        {
            if(nums[i]>currmax &&(k==i || k>i+1) )
                currmax=nums[i];
        }
        return currmax;
            
    }
};