class Solution {
public:
    vector<vector<int>> res;
    void dfs(int start,vector<int> &can, vector<int> &s,int sum, int t)
    {
        for(int i=start;i<can.size()&&sum+can[i]<=t;++i)
        {
            s.push_back(can[i]);
            if(sum+can[i]==t)
                res.push_back(s);
            else
                dfs(i,can,s,sum+can[i],t);
            s.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& can, int target) {
        sort(can.begin(),can.end());
        vector<int> tmp;
        dfs(0,can,tmp,0,target);
        return res;
    }
};