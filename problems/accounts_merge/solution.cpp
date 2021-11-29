class Solution {
public:
    unordered_map<string, set<string>> mp;
    unordered_map<string, bool> vis;
    vector<vector<string>> res;
    void dfs(string email, vector<string> &comp)
    {
        comp.push_back(email);
        vis[email] = true;
        for(string s : mp[email])
        {
            if(!vis.count(s) || !vis[s])
                dfs(s, comp);
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        for(int i=0; i<accounts.size(); ++i)
        {
            for(int j=2; j<accounts[i].size();++j)
            {
                mp[accounts[i][1]].insert(accounts[i][j]);
                mp[accounts[i][j]].insert(accounts[i][1]);
            }
            
        }
        
        for(int i=0; i<accounts.size(); ++i)
        {
            if(!vis.count(accounts[i][1]) || !vis[accounts[i][1]])
            {
                vector<string> comp;
                comp.push_back(accounts[i][0]);
                dfs(accounts[i][1], comp);
                sort(comp.begin() + 1, comp.end());
                res.push_back(comp);
            }
        }
        
        return res;
            
    }
};