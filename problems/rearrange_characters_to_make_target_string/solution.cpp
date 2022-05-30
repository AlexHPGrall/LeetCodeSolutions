class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int tFreq[26] ={};
        int freq[26]={};
        int res=INT_MAX;
        for(char c:target)
        {
            tFreq[c-'a']++;
        }
        for(char c:s)
        {
            if(!tFreq[c-'a'])
                continue;
            freq[c-'a']++;
        }
        for(int i=0;i<26;++i)
        {
            if(tFreq[i])
                res=min(res, freq[i]/tFreq[i]);
        }
        if(res==INT_MIN)
            return 0;
        return res;
    }
};