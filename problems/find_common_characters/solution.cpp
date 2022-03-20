class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int totalFreq[26]={0};
        for(char c:words[0])
            totalFreq[c-'a']++;
        for(int j=1;j<words.size();++j)
        {
            string s=words[j];
            int freq[26]={0};
            for(char c:s)
                freq[c-'a']++;
            for(int i=0;i<26;++i)
            {
                totalFreq[i]=min(freq[i],totalFreq[i]);
            }
        }
        vector<string> res;
        for(int i=0; i<26;++i)
        {
            string s;
            s.push_back(i+'a');
            while(totalFreq[i])
            {
                res.push_back(s);
                totalFreq[i]--;
            }
        }
        return res;
    }
};