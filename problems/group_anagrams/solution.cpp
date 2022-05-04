class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<int>> map;
        for(int m=0; m<strs.size(); ++m)
        {
            int freq[26]={0};
            for(char c:strs[m])
            {
                freq[c-'a']++;
            }
            string s;
            for(int i=0; i<26;++i)
            {
                for(int j=0; j<freq[i];++j)
                    s.push_back('a'+i);
            }
            map[s].push_back(m);
        }
        vector<vector<string>> res;
        for(auto &[key, val]:map)
        {
            vector<string> tres;
            for(int i:val)
                tres.push_back(strs[i]);
            res.push_back(tres);
        }
        return res;
    }
};