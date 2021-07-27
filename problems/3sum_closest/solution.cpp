class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int Min = nums[0] + nums[1] + nums[2];
        
        if(Min == target)
            return target;
        for(int i =0; i<n-2; ++i)
        {
           int l =i+1;
           int r = n-1;
           int curr;
           while(l<r)
           {
               curr =nums[i] + nums[l] + nums[r];
               if(curr == target)
                return target;
               if(abs(curr-target)<abs(Min-target))
                   Min = curr;
               if(curr <target)
                   ++l;
               else if(curr>target)
                   --r;
               
           }
        }
        return Min;
    }
};