class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n=nums.size();
        vector<bool> vis(n,false);
        int res=0;
        for(int i= 0;i<n;++i)
        {
            if(vis[i])
                continue;
            int curr=0;
            int j=i;
            while(!vis[j])
            {
                vis[j]=true;
                j=nums[j];
                ++curr;
            }
            res=max(curr, res);
        }
        return res;
    }
};