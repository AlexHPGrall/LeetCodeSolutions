class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> range(n);
        unordered_set<int> RangeSet;
        int res =0;
        int r = 1;
        int l=0;
        int sum =nums[0];
        for(int i =0; i <n; ++i)
        {
            l=i;
            int j= max(r-1, l);
            
           
            RangeSet.insert(nums[i]);
            
            while(++j<n)
            {
                 
                
                if(RangeSet.find(nums[j]) != RangeSet.end())
                    break;
                else{
                    RangeSet.insert(nums[j]);
                    sum += nums[j];
                    }
                
            }
            
            RangeSet.erase(nums[l]);
            r = j;
            res = max(sum,res);
            if(j >= n)
                break;
            if(r>l+1)
            sum-=nums[l];
            
        }
        return res;
    }
    
        
};