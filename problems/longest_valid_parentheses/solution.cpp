class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.size(), 0);
        int res=0;
        for(int i=1;i<s.size();++i)
        {
            if(s[i]=='(')
                continue;
            if(s[i-1]=='(')
            {
                dp[i]=2;
                if(i-2>=0)
                    dp[i]+=dp[i-2];
            }
            else if(i-dp[i-1]-1>=0 &&s[i-dp[i-1]-1]=='(')
            {
                dp[i]=dp[i-1]+2;
                if(i-dp[i-1]-2>=0)
                    dp[i]+=dp[i-dp[i-1]-2];
            }
            res=max(res,dp[i]);
        }
        return res;
    }
};