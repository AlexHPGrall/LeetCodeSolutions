class Solution {
public:
//BFS
    int shortestPathLength(vector<vector<int>>& graph) {
        
        int n=graph.size();
        if(n==1)
            return 0;
        
        int endmask=(1<<n)-1;  
        vector<vector<int>> vis(n, vector<int>(endmask, 0));
        
        queue<vector<int>> q;
        for(int i=0;i<n;++i)
        {
            q.push({i,(1<<i)});
            vis[i][1<<i]=1;
        }
        int dist=0;
        
        while(!q.empty())
        {
           int count=q.size();
            
            while(count)
            {
                int node=q.front()[0];
                int mask=q.front()[1];
                q.pop();
                
                for(int nei:graph[node])
                {
                    int nextmask=mask|(1<<nei);
                    
                    if(nextmask==endmask)
                        return dist+1;
                    if(vis[nei][nextmask])
                        continue;
                    vis[nei][nextmask]=1;
                    q.push({nei,nextmask});
                }
                count--;
            }
            dist++;
        }
        return -1;
    }
};