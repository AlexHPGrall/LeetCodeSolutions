class Solution {
public:
    vector<vector<int>> dp=vector<vector<int>>(21, vector<int>(31,-1));
    bool rec(string &s, string &p, int i, int j)
    {
        //cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
        if(i>=s.size() && j == p.size())
            return true;
        if(j==p.size())
        {
            return false;
        }
        
        if(dp[i][j]!=-1)
          return dp[i][j];
        bool res=false;
       

        if(p[j]=='*')
        {
            res= rec(s,p,i,j+1);
            if(i<s.size() && (p[j-1]==s[i] || p[j-1] == '.'))
                res= res || rec(s,p,i+1,j);
        
        }
        else
        {
            
           if(i<s.size()&&(s[i]==p[j] || p[j]=='.'))
               res= rec(s,p, i+1, j+1);
            if(j<p.size()-1 && p[j+1] =='*')
               res=  res||rec(s,p,i,j+2);
        }
        
        dp[i][j]=res?1:0;
        //if(i<s.size()&&((res && !dp[i][j])||(!res&&dp[i][j])))
            //cout<<i<<' '<<j<<' '<<res<<' '<<dp[i][j]<<endl;
        return res;
    }
    
    bool isMatch(string s, string p) {
        return rec(s,p,0,0);
    }
};