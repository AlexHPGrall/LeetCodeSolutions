class Solution {

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> parent(n,0);
        
        for(int i=0; i<n;++i)
        {
            if(graph[i].size() && parent[i]==0)
            {
                parent[i]=1;
                queue<int> q;
                q.push(i);
                while(!q.empty())
                {
                    int cur=q.front();
                    q.pop();
                    for(int nei:graph[cur])
                    {
                        if(parent[nei]==0)
                        {
                            parent[nei]=-parent[cur];
                            q.push(nei);
                        }
                        else if(parent[nei]!=-parent[cur])
                            return false;
                    }
                }
            }
        }
        return true;
    }
};