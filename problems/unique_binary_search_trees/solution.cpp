class Solution {
public:
    
    int numTrees(int n) {
        static vector<int> dp(20,1);
        if(n>1 && dp[n]==1)
        {
            dp[n]=0;
            for(int i=0; i<(n/2); ++i)
            {
                
                dp[n] += 2*numTrees(i)*numTrees(n-1-i);
            }
                
            if(n%2==1)
                dp[n]+= numTrees(n/2)*numTrees(n/2);
                   
        }
        
        return dp[n];
    }
};