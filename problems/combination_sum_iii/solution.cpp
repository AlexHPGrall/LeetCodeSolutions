class Solution {
public:
    vector<vector<int>> res;
    void dfs(int num, int k, int n, int mask, vector<vector<int>> &vis)
    {
        
        if(k==0)
        {
            if(num==n)
            {
                vector<int> tmp;
                for(int i=1;i<=9;++i)
                    if(mask & (1<<i))
                        tmp.push_back(i);
                res.push_back(tmp);
            }
            return;
        }
        for(int i=1;i<=9;++i)
        {
            if(mask&(1<<i) || vis[num+i][mask|(1<<i)])
                continue;
            vis[num+i][mask|(1<<i)]=1;
            dfs(num+i, k-1, n, mask|(1<<i), vis);
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> vis(83, vector<int>(1<<10,0));
        dfs(0,k,n,0,vis);
        return res;
    }
};