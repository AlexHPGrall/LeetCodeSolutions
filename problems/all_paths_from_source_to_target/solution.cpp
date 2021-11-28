class Solution {
public:
    vector<vector<int>> res;
    vector<int> vis;
    int n;
    void dfs(vector<int> path, int node, vector<vector<int>>& graph)
    {
        if(node == n-1)
        {
            res.push_back(path);
            return;
        }
        vis[node]=1;
        for(int i=0; i<graph[node].size(); ++i)
        {
            if(!vis[graph[node][i]])
            {
                path.push_back(graph[node][i]);
                dfs(path, graph[node][i], graph);
                path.pop_back();
            }
        }
        vis[node]=0;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
         n = graph.size();
        vis.resize(n,0);
        vector<int> path = {0};
        dfs(path, 0, graph);
        
        return res;
    }
};