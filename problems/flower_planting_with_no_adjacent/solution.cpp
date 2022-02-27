class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> f(n,-1);
        vector<int> vis(n,0);
        vector<vector<int>> graph(n);
        for(auto v:paths)
        {
            graph[v[0]-1].push_back(v[1]-1);
            graph[v[1]-1].push_back(v[0]-1);
        }
        
        for(int i=0;i<n;++i)
        {
            if(vis[i])
                continue;
            queue<int> q;
            q.push(i);
            vis[i]=1;
            
            while(!q.empty())
            {
                int count=q.size();
                while(count)
                {
                    int node =q.front();
                    q.pop();
                    vector<int> pos(4,1);
                    for(int j:graph[node])
                    {
                        
                        if(!vis[j])
                        {
                            vis[j]=1;
                            q.push(j);
                            continue;
                        }
                        if(f[j]!=-1)
                            pos[f[j]-1]=0;
                        
                        
                    }
                    
                    for(int k=0;k<4;++k)
                    {
                        if(pos[k])
                        {
                            f[node]=k+1;
                            break;
                        }
                    }
                    count--;
                }
            }
        }
        return f;
        
    }
};