class Solution {
public:
    string convert(string &s)
    {
        char map[26]={};
        int idx=0;
        string w(s.size(), ' ');
        for(int i=0;i<s.size();++i)
        {
            char c=s[i];
            if(!map[c-'a'])
            {
                map[c-'a']='a'+idx;
                ++idx;
            }
            w[i]=map[c-'a'];
        }
        return w;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        string pat=convert(pattern);
        for(string &w:words)
        {
            string v=convert(w);
            if(v==pat)
                res.push_back(w);
        }
        
        return res;
    }
};