class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> res(k,0);
        unordered_map<int, unordered_map<int, int>> mp;
        unordered_map<int, int> cnt;

        for(auto &v:logs)
        {
            
            if(!mp[v[0]].count(v[1]))
            {
                mp[v[0]][v[1]]=1;
                cnt[v[0]]++;
            }
        }
        for(auto& [k, c]:cnt)
        {
            res[c-1]++;
        }
        return res;
    }
};