

class Solution {

public:
    unordered_map<int, vector<int>> dp;
    int Dfs(int index, int n, vector<int>& nums, int states)
    {
        if(index == nums.size())
            return 0;
        if(dp.count(states) && dp[states][index]!=-1)
            return dp[states][index];
        int res=0;
        dp[states].resize(nums.size(),-1);
        for(int i=0; i<n;++i)
        {
            int state=(states>>(2*i))&3;
            int prev=states;
            
            if(state==2)
                continue;
        
            if(state==1)
            {
                
                states&=~((1)<<((2*i)));
                states|=((2)<<((2*i)));
                
                res=max(res, (nums[index]&(i+1))+Dfs(index+1,n,nums,states));
                states=prev;
            }
            if(state == 0)
            {
                //cout<<states<<' ';
                states|=((1)<<(2*i));
                //cout<<states<<endl;
                res=max(res,(nums[index]&(i+1))+Dfs(index+1,n,nums,states));
                states=prev;
            }
        }
        dp[states][index]=res;
        return res;
    }
    int maximumANDSum(vector<int>& nums, int numSlots) {
        
        return Dfs(0, numSlots, nums, 0);

    }
};