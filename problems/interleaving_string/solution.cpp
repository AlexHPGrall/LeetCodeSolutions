class Solution {
public:
    
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.size();
        int n=s2.size();
        if(s3.size()!=m+n)
            return false;
        //vector<vector<int>> dp(m+1, vector<int>(n+1, false));
        vector<bool> dp(n+1,false);
            for(int i=0;i<=m;++i)
            {
                for(int j=0;j<=n;++j)
                {
                    int k=i+j-1;
                    if(i==0 && j==0)
                        dp[j]=true;
                    else if(i>0 && s1[i-1] == s3[k] && dp[j])
                        dp[j]=true;
                    else if(j>0 && s2[j-1]==s3[k] && dp[j-1])
                        dp[j]=true;
                    else
                        dp[j]=false;
                }
                
            }
        return dp[n];
        }
};