class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prereq) {
        unordered_map<int, vector<int>> adj;
        vector<int> deg(n, 0);
        vector<int>res;
        queue<int> q;
        for(vector<int> p:prereq)
        {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
            
            deg[p[0]]++;
        }
               
        for(int i=0;i<n;++i)
        {
            if(deg[i]==0)
                q.push(i);
        }
        
        while(!q.empty())
        {
            int i=q.front();
            q.pop();
            res.push_back(i);
            for(int j : adj[i])
            {
                deg[j]--;
                if(deg[j]==0)
                    q.push(j);
            }
        }
        
        return (res.size()==n)?res:vector<int>();
        
    }
};