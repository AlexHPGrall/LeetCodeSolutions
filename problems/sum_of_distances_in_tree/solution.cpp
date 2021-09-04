class Solution {
public:
    unordered_map<int, vector<int>> mp;
    vector<int> count;
    vector<int> sum;
    int n;
    
    void dfs1(int node, int parent)
    {
        for(int child:mp[node])
        {
            if(child==parent)
                continue;
            dfs1(child, node);
            count[node]+=count[child];
            sum[node]+=sum[child]+count[child];
        }
    }
    
    void dfs2(int node, int parent)
    {
        for(int child:mp[node])
        {
            if(child==parent)
                continue;
            
            
            sum[child] =sum[node] - count[child] +(n-count[child]);
            dfs2(child, node);
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
          this->n=n;
        cout<<n;
        count.resize(n,1);
        sum.resize(n,0);
        for(auto v:edges)
        {
            mp[v[0]].push_back(v[1]);
            mp[v[1]].push_back(v[0]);
        }
        for(auto it:mp)
        {
            cout<<it.first<<": ";
            for(int i:it.second)
            {
                cout<<i<<", ";
            }
            cout<<endl;
        }
        dfs1(0,0);
        dfs2(0,0);
        
        return sum;
        
    }
};