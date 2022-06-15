class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(begin(words),end(words),[](const string &a, const string &b)
             {
                 return a.size()<b.size();
             });
        vector<int> dp(n,0);
        unordered_map<string, int> vis;
        int res=1;
        for(int i=0;i<n;++i)
        {
            vis[words[i]]=i;
            string key;

            for(int j=0;j<words[i].size();++j)
            {
                key=words[i].substr(0,j);
                key+=words[i].substr(j+1);
                if(vis.count(key))
                    dp[i]=max(dp[i], dp[vis[key]]);
                
            }
            dp[i]+=1;
            res=max(res, dp[i]);
        }
        return res;
    }
};