class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string,char> mp1;
        unordered_map<char, string> mp2;
        int i=0;
        int j=0;
        for(;i<pattern.size()&& j<s.size();++i)
        {
            string word;
            char pat=pattern[i];
            //cout<<i<<" "<<j<<endl;
            while(j<s.size()&&s[j]!=' ')
            {
                word.push_back(s[j]);
                ++j;
            }
            if(j<s.size())
                ++j;
            if(mp2.count(pat) && mp2[pat]!=word)
                return false;
            if(mp1.count(word) && mp1[word]!=pat)
                return false;
            if(!mp1.count(word))
            {
                mp1[word]=pat;
                mp2[pat]=word;
            }
        }
        
        if(j!=s.size()||i!=pattern.size())
            return false;
        return true;
    }
};