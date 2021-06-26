class Solution {
public:
    vector<int> parents;
    int find(int x)
    {
        if(parents[x] == x)
            return x;
        else 
            return find(parents[x]);
    }
    bool Union(int x, int y)
    {
        int xp = find(x), yp =find(y);
        if(xp == yp)
            return false;
        else
           return parents[xp]= yp;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        parents.resize((edges.size()+1));
        iota(parents.begin(), parents.end(), 0);
        for(auto const &edge:edges)
        {
            if(!Union(edge[0], edge[1]))
                return edge;
        }
        return {};
    }
};