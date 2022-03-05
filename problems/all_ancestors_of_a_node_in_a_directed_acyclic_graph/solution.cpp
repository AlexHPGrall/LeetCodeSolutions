class Solution {
public:
    vector<vector<int>> res;
    void Dfs(int node, vector<vector<int>> &anc, set<int> &st)
    {
        
        if(!res[node].empty())
        {
            for(int i:res[node])
                st.insert(i);
            return;
        }
        set<int> st2;
        for(int a:anc[node])
        {
            Dfs(a,anc,st2);
            st.insert(a);
            st.merge(st2);
            st2.clear();
        }
        
        for(auto i:st)
            res[node].push_back(i);
        
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> anc(n);
        vector<vector<int>> graph(n);
        res.resize(n);
        for(vector<int> &e:edges)
        {
            graph[e[0]].push_back(e[1]);
            anc[e[1]].push_back(e[0]);
        }

        for(int i=0;i<n;++i)
            if(graph[i].empty())
            {
                set<int> st;
                Dfs(i, anc,st);
            }

        
        
        
        
                
        return res;
    }
};