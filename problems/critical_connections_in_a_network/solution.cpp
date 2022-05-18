class Solution {
public:
    int time=0;
    vector<vector<int>> res;
    void Dfs(int node, int parent,vector<vector<int>> &graph, vector<int> &lowlink, vector<int> &dist)
    {
        ++time;
        dist[node]=time;
        lowlink[node]=time;
        for(int nei:graph[node])
        {
            if(nei==parent)
                continue;
            if(!dist[nei])
            {
                Dfs(nei,node,graph,lowlink,dist);
                if(lowlink[nei]>dist[node])
                    res.push_back({node,nei});
                lowlink[node]=min(lowlink[node], lowlink[nei]);
            }
            else
            {
                lowlink[node]=min(dist[nei],lowlink[node]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        vector<int> dist(n,0);
        vector<int> lowlink(n,0);
        for(auto &co:connections)
        {
            graph[co[0]].push_back(co[1]);
            graph[co[1]].push_back(co[0]);
        }
        Dfs(0,-1,graph, lowlink, dist);
        return res;
    }
};