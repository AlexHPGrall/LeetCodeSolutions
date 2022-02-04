class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int sum=0, res=0;
        unordered_map<int,int> mp;
        mp[0]=-1;
        for(int i=0;i<n;++i)
        {
            if(nums[i])
                sum+=1;
            else
                sum-=1;
            if(mp.count(sum))
                res=max(res, (i-mp[sum]));
            else
                mp[sum]=i;
        }
        
        return res;
    }
};