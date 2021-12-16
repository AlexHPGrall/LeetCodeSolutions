class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> tree(n);
        vector<int> res;
        if(n<2)
        {
            for(int i =0;i<n;++i)
            {
                res.push_back(i);
            }
            return res;
        }
        for(auto e : edges)
        {
            tree[e[0]].insert(e[1]);
            tree[e[1]].insert(e[0]);
        }
        queue<int> q;
        for(int i=0; i<n;++i)
        {
            if(tree[i].size()==1)
            {
                q.push(i);
            }
                
        }
        int remaining =n;
        while(remaining>2)
        {
            remaining-=q.size();
            int qsize=q.size();
            for(int i=0; i<qsize;++i)
            {
                int leaf=q.front();
                q.pop();
                int nei = *(tree[leaf].begin());
                tree[nei].erase(leaf);
                if(tree[nei].size() ==1)
                {
                    q.push(nei);
                }
            }
            
        }
        
        
        while(!q.empty())
        {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};