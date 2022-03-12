class Solution {
public:
    vector<vector<int>> graph;
    void Dfs(int node,vector<vector<int>>& C,vector<int> &vis)
    {
        for(int nei:graph[node])
        {
            if(vis[nei])
                continue;
            vis[nei]=1;
            Dfs(nei,C,vis);
        }   
    }
    int findCircleNum(vector<vector<int>>& C) {
        int n=C.size();
        graph.resize(n);
        vector<int> vis(n,0);
        int res=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(C[i][j])
                    graph[i].push_back(j);
            }
        }
        for(int i=0;i<n;++i)
        {
            if(vis[i])
                continue;
            vis[i]=1;
            res++;
            Dfs(i,C,vis);
        }
        return res;
    }
};