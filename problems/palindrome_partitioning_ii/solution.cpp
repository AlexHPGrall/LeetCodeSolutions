class Solution {
public:
    
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n+1);
        vector<vector<bool>> Pal(n, vector<bool>(n, false));
        dp[n] = 0;
        
       
        for(int i =n-1; ~i; --i)
        {
            int minP= dp[i+1] +1;
            
            for(int j=n-1; j>=i; --j)
            {
                if(i==j)
                    Pal[i][j]=true;
                else if(j==i+1)
                    Pal[i][j]=(s[i]==s[j]);
                else
                    Pal[i][j]=(Pal[i+1][j-1] && (s[i]==s[j]));
                
                if(Pal[i][j])
                    minP=min(minP, dp[j+1]+1);
            }
            
            dp[i] =minP;
        }
        
        return dp[0] -1;
    }
};