class Solution {
public:
    int minSteps(string s, string t) {
       int freq1[26]={0};
        int freq2[26]={0};
        for(char c:s)
            freq1[c-'a']++;
        for(char c:t)
            freq2[c-'a']++;
        int res=0;
        for(int i=0; i<26;++i)
        {
            res+=abs(freq1[i]-freq2[i]);
        }
        return res;
    }
};