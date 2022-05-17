class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int cFreq[26]={};
        vector<string> res;
        for(char c:words[0])
        {
            cFreq[c-'a']++;
        }
        
        for(int i=1;i<words.size();++i)
        {
            int freq[26]={};
            for(char c:words[i])
                freq[c-'a']++;
            for(int j=0; j<26;++j)
                cFreq[j]=min(freq[j],cFreq[j]);
        }
        for(int i=0; i<26;++i)
        {
            string s;
            s.push_back('a'+i);
            for(int j=0; j<cFreq[i];++j)
                res.push_back(s);
        }
        return res;
    }
};