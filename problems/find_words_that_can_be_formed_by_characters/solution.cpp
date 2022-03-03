class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int freq[26]={};
        for(char c:chars)
        {
            freq[c-'a']++;
        }
        int res=0;
        for(string &s:words)
        {
            int sfreq[26]={};
            bool ok=true;
            for(char &c:s)
            {
                sfreq[c-'a']++;
                if(sfreq[c-'a']>freq[c-'a'])
                {ok=false;break;}
            }
            if(ok)
                res+=s.length();
        }
        return res;
    }
};