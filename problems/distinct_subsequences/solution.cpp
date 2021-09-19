class Solution {
public:
    
    
    
    int numDistinct(string s, string t) {
        
        vector<vector<uint32_t>> dp(s.size()+1, vector<uint32_t>(t.size()+1, 0));
        for(int i=s.size()-1, j=t.size()-1; i>=0;--i)
        {
            dp[i][j]=(s[i]==t[j])?dp[i+1][j]+1:dp[i+1][j];
        }
        for(int j=t.size()-2, k=1; j>=0;--j,++k)
        {
            for(int i=s.size()-(1+k); ~i; --i)
            {
                if(dp[i][j+1])
                {
                    dp[i][j]=(s[i]==t[j])?dp[i+1][j]+dp[i+1][j+1]:dp[i+1][j];
                }
            }
        }
        return dp[0][0];
        
        
        
        
    }
};
