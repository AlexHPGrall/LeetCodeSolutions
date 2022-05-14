class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n+1);
        for(auto& v:times)
        {
            graph[v[0]].push_back({v[1],v[2]});
        }
        vector<int> dist(n+1,INT_MAX);
        int v=0;
        priority_queue<pair<int,int>> q;
        q.push({0,k});
        dist[k]=0;
        int res=0;
        while(!q.empty())
        {
            auto [d, node]=q.top();
            q.pop();
            
            if(dist[node]<d)
                continue;
            for(auto [nei, neiD]:graph[node])
            {
                
                if(d+neiD<dist[nei])
                {
                    q.push({d+neiD,nei});
                    dist[nei]=d+neiD;
                }
                
            }
           
        }
        for(int i =1; i<=n;++i)
        {
            if(dist[i]==INT_MAX)
                return -1;
            res=max(dist[i],res);
        }
        return res;
        
    }
};