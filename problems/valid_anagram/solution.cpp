class Solution {
public:
    bool isAnagram(string s, string t) {
        int freqS[26]={}, freqT[26]={};
        if(s.size()!=t.size())
            return false;
        for(int i=0; i<t.size(); ++i)
        {
            freqS[s[i]-'a']++;
            freqT[t[i]-'a']++;
        }
        for(int i=0; i<26;++i)
        {
            if(freqS[i]!=freqT[i])
                return false;
        }
        return true;
    }
};