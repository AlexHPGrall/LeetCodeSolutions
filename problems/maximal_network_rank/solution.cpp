class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> con(n, vector<int>(n,0));
        vector<int> roadCount(n,0);
        for(auto &r:roads)
        {
            roadCount[r[0]]++;
            roadCount[r[1]]++;
            con[r[0]][r[1]]=1;
            con[r[1]][r[0]]=1;
        }
        int res=0;
        for(int i=0; i<n-1; ++i)
        {
            for(int j=i+1; j<n;++j)
            {
                res=max(res,roadCount[i]+roadCount[j]-con[i][j]);
            }
        }
        return res;
    }
};