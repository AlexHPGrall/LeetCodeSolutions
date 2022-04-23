class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int res=0;
        int currsum=0;
        unordered_map<int, int> mp;
        mp[0]=1;
        for(int i=0;i<nums.size();++i)
        {
            currsum+=nums[i];
            
            res+=mp[currsum-goal];
            mp[currsum]++;
        }
        return res;
    }
};