class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int maxL=gcd(str1.size(), str2.size());
        string s;
        for(int i=0;i<maxL;++i)
        {
            if(str1[i] != str2[i])
                return "";
            else
                s.push_back(str1[i]);
        }
        for(int i=0; i<str1.length();++i)
            if(str1[i]!=s[i%maxL])
                return "";
        for(int i=0; i<str2.length();++i)
            if(str2[i]!=s[i%maxL])
                return "";
        return s;
    }
};