class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length()<s1.length())
            return false;
        vector<int> freq(26,0), wind(26,0);
        int len=s1.length();
        for(int i=0; i<s1.length(); ++i)
        {
            freq[s1[i]-'a']++;
            wind[s2[i]-'a']++;
        }
        if(freq==wind)
            return true;
        for(int i=len; i<s2.length();++i)
        {
            wind[s2[i-len]-'a']--;
            wind[s2[i]-'a']++;
            if(freq==wind)
                return true;
        }
        return false;
    }
};