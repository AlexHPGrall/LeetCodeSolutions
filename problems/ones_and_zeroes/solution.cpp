class Solution {
public:
    int dp[101][101][600]={};
    int Dfs(int z, int o, int m, int n, vector<pair<int, int>> &zno, int index)
    {
        if(z>m || o>n)
            return INT_MIN;
        if(index==zno.size())
            return 0;
        if(dp[z][o][index]!=0)
            return dp[z][o][index];
        dp[z][o][index]= max(1+Dfs(z+zno[index].first, o+zno[index].second, m,n, zno,index+1), Dfs(z,o,m,n,zno,index+1));
        return dp[z][o][index];
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> zno;
        for(auto &s:strs)
        {
            int z=0;
            int o=0;
            for(auto c:s)
            {
                if(c=='0')
                    z++;
                else
                    o++;
                
            }
            zno.push_back({z,o});
        }
        
        return Dfs(0,0,m,n,zno,0);
    }
};