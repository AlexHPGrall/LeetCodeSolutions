class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n=nums.size();
        int currsum=0;
        int res=0;
        mp[0]=1;
        for(int i=0;i<n;++i)
        {
            currsum+=nums[i];
            res+=mp[currsum-k];
            mp[currsum]++;
        }
        
        return res;
    }
};