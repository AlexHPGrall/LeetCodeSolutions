#define pii pair<int, int>

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int n) {
        vector<vector<pii>> graph(n);
        for(auto e:edges)
        {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        
        }
        
        map<int, int> dist;
        dist[0] = 0;
        for (int i = 1; i < n; ++i)
            dist[i] = M+1;

        map<pii, int> used;
        int ans = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0,0});
        
        for(;!pq.empty();)
        {
            pii curr = pq.top();
            pq.pop();
            int node =curr.second;
            int d=curr.first;
            
            if(d>dist[node])
                continue;
            
            ans++;
            for(auto p:graph[node])
            {
                int nei = p.first;
                int weight = p.second;
                used[{node, nei}] =min(weight, M-d);
                int alt=d+1+weight;
                if(alt<min(M+1,dist[nei]))
                {
                    pq.push({alt,nei});
                    dist[nei]=alt;
                }
            }
            
            
        }
       
        for(auto e: edges)
        {
            ans += min(used[{e[0],e[1]}]+used[{e[1],e[0]}], e[2]);
        }
        return ans;
        
    }
};
