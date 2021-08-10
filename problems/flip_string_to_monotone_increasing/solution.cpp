class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int>dp(n);
        int ones=0, zeroes =0;
        for(int i=0; i<n; ++i)
        {
            dp[i]=ones;
            if(s[i] == '1')
                ones++;
            else
                zeroes++;
        }
        int res=min(ones, zeroes);
        for(int i=1; i<n; ++i)
        {
            int cur1=dp[i];
            int cur0 =(n-i)-(ones-dp[i]);
            res=min(res,cur1+cur0);
        }
        
        return res;
    }
};