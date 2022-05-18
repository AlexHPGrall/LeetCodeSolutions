class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
       string res;
        unordered_map<string, string> mp;
        for(auto &v:knowledge)
            mp[v[0]]=v[1];
        int i=0;
        while(i<s.size())
        {
            if(s[i]=='(')
            {
                string key;
                ++i;
                while(s[i]!=')')
                {
                    key.push_back(s[i]);
                    ++i;
                }
                if(mp.count(key))
                    res.append(mp[key]);
                else
                    res.push_back('?');
            }
            else
                res.push_back(s[i]);
            ++i;
        }
        return res;
    }
};