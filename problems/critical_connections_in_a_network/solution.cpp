class Solution {
public:
    int time=0;
    vector<vector<int>> res;
    void Tarjan(vector<int> &dist, vector<int> &low, int node, int parent, vector<vector<int>> &graph)
    {
        ++time;
        dist[node]=time;
        low[node]=time;
        for(int nei:graph[node])
        {
            if(nei==parent)
                continue;
            if(!dist[nei])
            {
                Tarjan(dist, low, nei, node ,graph);
                if(dist[node]<low[nei])
                    res.push_back({node,nei});
                low[node]=min(low[node],low[nei]);
            }
            else
            {
                low[node]=min(low[node],dist[nei]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        vector<int> dist(n,0);
        vector<int> low(n,0);
        for(auto &e:connections)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        Tarjan(dist,low,0,0,graph);
        return res;
    }
};