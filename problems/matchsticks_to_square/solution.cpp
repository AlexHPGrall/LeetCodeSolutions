class Solution {
public:
    
    
    int target;
    
    bool dfs(int i, vector<int>& m,  vector<int> &s)
    {
        
        if(i==m.size())
        {
            return (s[0]==s[1] && s[1]==s[2]&& s[2]==s[3]);
        }
        //if(dp.count(mask))
          //  return dp[mask];
        for(int j=0; j<4;++j)
        {
            if(s[j]+m[i]>target)
                continue;
            int k = j;
            while (--k >= 0) 
                if (s[k] == s[j]) 
                    break;
            if (k != -1) continue;
            s[j]+=m[i];
            if(dfs(i+1, m,s))
                return true;
            s[j]-=m[i];
            
        }
        //dp[mask] =res;
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        vector<int> s(4,0);
        int sum=0;
        for(int n:matchsticks)
            sum+=n;
        if(sum%4!=0)
            return false;
        target =sum/4;
        sort(matchsticks.rbegin(), matchsticks.rend());
        return dfs(0, matchsticks, s);
    }
};
