class Solution {
public:
    void Djikstra(int src, vector<vector<pair<int,int>>> graph, vector<long long> &dist)
    {
        priority_queue<pair<long long, int>> q;
        q.push({0,src});
        while(!q.empty())
        {
            long long d=q.top().first;
            int node=q.top().second;
            q.pop();
            if(d>dist[node])
                continue;
            for(pair p:graph[node])
            {
                int nei =p.first;
                int e=p.second;
                if(dist[nei]>d+e)
                {
                    dist[nei]=d+e;
                    q.push({dist[nei],nei});
                }
            }
        }
        
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int,int>>> graph(n);
        vector<vector<pair<int,int>>> rgraph(n);
        for(auto &e:edges)
        {
            graph[e[0]].push_back({e[1],e[2]});
            
            rgraph[e[1]].push_back({e[0],e[2]});
            
        }
        vector<long long> dist1(n,LLONG_MAX);
        dist1[src1]=0;
        Djikstra(src1, graph, dist1);
        vector<long long> dist2(n,LLONG_MAX);
        dist2[src2]=0;
        Djikstra(src2, graph, dist2);
        vector<long long> distd(n,LLONG_MAX);
        distd[dest]=0;
        if(dist1[dest]==LLONG_MAX || dist2[dest] ==LLONG_MAX)
            return -1;
        Djikstra(dest, rgraph, distd);
        long long res=dist1[dest]+dist2[dest];
        for(int i=0; i<n;++i)
        {
            if(dist1[i] ==LLONG_MAX || dist2[i] ==LLONG_MAX || distd[i] ==LLONG_MAX)
                continue;
            res=min(res, dist1[i]+dist2[i]+distd[i]);
        }
        return res;
    }
};