class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res=0;
        int n = nums.size();
        
        for(int i =2; i<n; ++i)
        {
          int start =0, end = i-1;
            while(start<end)
            {
                if(nums[i]<nums[start] + nums[end])
                {
                    res+= end -start;
                    end--;
                }
                else
                {
                    start++;
                }
            }
        }
            
        return res;
    }
};