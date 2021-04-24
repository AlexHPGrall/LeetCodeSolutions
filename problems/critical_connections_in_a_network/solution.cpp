class Solution {
    vector<vector<int>> Br;
    int Time;
public:
    void Tarjan(int u, int p,vector<int>& low, vector<int>& dist, vector<vector<int>>& adj)
    {
        low[u]= dist[u] =++Time;
        for(auto& v:adj[u])
        {
            if(v==p)
                continue;
            if(!dist[v])
            {
                Tarjan(v, u,low, dist, adj);
                if(dist[u]<low[v])
                    Br.push_back({u, v});
                low[u] = min(low[u], low[v]);
            }
            else{
                low[u]= min(low[u], dist[v]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        vector<int> low(n);
        vector<int> dist(n,0);
        Time=0;
        for(auto edge:connections)
        {
           adj[edge[0]].push_back(edge[1]);
           adj[edge[1]].push_back(edge[0]);
        }
        Tarjan(0,0, low, dist, adj);
        
        return Br;
    }
};