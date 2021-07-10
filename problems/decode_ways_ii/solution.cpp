class Solution {
public:
    ulong GetDecodingNumber(string &s, int index)
    {
         if(s[index] == '0')
         {
                            
             return (s[index-1] == '*')?2:1;
         }
            
        if(s[index] == '*' && s[index-1] == '1')
            return 18;
        if(s[index] == '*' && s[index -1] == '2')
            return 15;
        if(s[index] == '*' && s[index-1]== '*')
            return 96;
        if(s[index] != '*'&& s[index]<'7' && s[index-1]== '*')
            return 11;
        if(s[index] != '*'&& s[index]>='7' && s[index-1]== '*')
            return 10;
        if(s[index] == '*' || s[index-1] == '*')
            return 9;
        if(s[index]>='7' && s[index-1]== '2')
            return 1;
       
        if(s[index]<'7' && s[index-1]== '2')
            return 2;
        if(s[index-1]== '1')
            return 2;
        return 1;
    }
    ulong GetCombinedNumber(string &s, int index)
    {
        if(s[index] == '*' && s[index-1] == '1')
            return 9;
        if(s[index] == '*' && s[index -1] == '2')
            return 6;
        if(s[index] == '*' && s[index-1]== '*')
            return 15;
        if(s[index] != '*'&& s[index]<'7' && s[index-1]== '*')
            return 2;
        if(s[index] != '*'&& s[index]>='7' && s[index-1]== '*')
            return 1;
        if(s[index]<'7' && s[index-1]== '2')
            return 1;
        if(s[index-1]== '1')
            return 1;
        return 0;
    }
    int numDecodings(string s) {
        int n =s.size();
        if(n==0||s[0] == '0')
            return 0;
        int mod = 1e9+7;
        vector<long> dp(n);
        
        dp[0] = (s[0] == '*')?9:1;
        if(n>1)
        {
            dp[1] =GetDecodingNumber(s, 1);
            if(s[1]=='0'&& s[0] != '1' && s[0]!= '2'&& s[0]!='*')
                return 0;
        }
        
        for(int i =2; i<n;++i)
        {
            
            if(s[i] =='0')
            {
                if(s[i-1] != '1' && s[i-1]!= '2'&&s[i-1]!='*')
                    return 0;
                dp[i] = ((s[i-1] == '*')?2*dp[i-2]:dp[i-2])%mod;
                continue;
            }
            dp[i] = (s[i] == '*')?9*dp[i-1]:dp[i-1];
            dp[i] += dp[i-2]*GetCombinedNumber(s, i);
            dp[i]%=mod;
        }
        
        return dp[n-1]%mod;
    }
};