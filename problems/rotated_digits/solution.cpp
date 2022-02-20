class Solution {
public:
    int rotatedDigits(int n) {
        static vector<int> dp(1e4+1, -1);
        if(dp[n]!=-1)
            return dp[n];
        dp[0]=0;
        for(int i=1;i<1e4+1;++i)
        {
            int k=i;
            dp[i]=dp[i-1];
            bool ok=false;
            while(k)
            {
                int rem=k%10;
                if(rem == 2 || rem== 5 || rem== 6 || rem==9 )
                {
                    ok=true;
                }
                else if(rem== 3 || rem == 4 || rem == 7)
                {
                    ok=false;
                    break;
                }
                k/=10;
            }
            if(ok)
                dp[i]+=1;
        }
        
        return dp[n];
    }
};