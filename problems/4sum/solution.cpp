class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0; i<n-3; i++)
        {
            for(int j=i+1; j<n-2; ++j)
            {
                int left= j+1, right =n-1;
                
                while(left<right)
                {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum<target)
                    {
                        ++left;
                    }
                    else if(sum>target)
                    {
                        --right;
                    }
                    else
                    {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while(++left<right && nums[left] == nums[left-1])
                        {}
                        while(left<--right && nums[right] == nums[right+1])
                        {}
                    }
                    
                }
                while(j<n-3 && nums[j]==nums[j+1])
                {++j;}
            }
            while(i<n-4 && nums[i]==nums[i+1])
                {++i;}
        }
        return res;
    }
};