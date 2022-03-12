class Solution {
public:
    int res;
    vector<int> vis;
    void Dfs(int node, vector<vector<int>> &graph)
    {
        for(int n:graph[node])
        {
            
            if(vis[abs(n)])
               continue;
            vis[abs(n)]=1;
            if(n>0)
               res++;
            Dfs(abs(n),graph);
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
    
        vector<vector<int>> graph(n);
        
        for(vector<int> &v:connections)
        {
            
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(-v[0]);
        }
        
        res=0;
        vis.resize(n,0);
        vis[0]=1;
        //cout<<"ok"<<endl;
        Dfs(0,graph);
        return res;
    }
};