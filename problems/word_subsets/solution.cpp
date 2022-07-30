class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int universal[26]={0};
        vector<string> res;
        for(string &w:words2)
        {
            int map[26]={};
            for(char c:w)
                map[c-'a']++;
            for(int i=0;i<26;++i)
                universal[i]=max(map[i], universal[i]);
        }
        for(string &w:words1)
        {
            int map[26]={};
            for(char c:w)
                map[c-'a']++;
            bool ok=true;
            for(int i=0;i<26;++i)
                if(map[i]<universal[i])
                {
                    ok=false;
                    break;
                }
            if(ok)
                res.push_back(w);
        }
        return res;
    }
};