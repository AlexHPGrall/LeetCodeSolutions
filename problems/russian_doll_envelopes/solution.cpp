class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& e) {
        sort(e.begin(),e.end(), [](auto &a, auto &b){
            if(a[0]==b[0])
                return b[1]<a[1];
            return a[0]<b[0];
        });
        
        vector<int> dp;
        for(auto &nv:e)
        {
            auto l=lower_bound(dp.begin(),dp.end(), nv[1]);
            if(l==dp.end())
                dp.push_back(nv[1]);
            else
                *l=nv[1];
        }
        return dp.size();
    }
};