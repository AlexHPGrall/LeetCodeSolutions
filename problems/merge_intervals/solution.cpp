class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& vals) {
        sort(vals.begin(), vals.end());
        vector<vector<int>> res;
        for(auto v:vals)
        {
            if(res.empty())
                res.push_back(v);
            else if(v[0]> res.back()[1])
                res.push_back(v);
            else
                res.back()[1]=max(res.back()[1], v[1]);
        }
        
        return res;
    }
};