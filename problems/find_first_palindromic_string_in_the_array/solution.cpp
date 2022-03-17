class Solution {
public:
    bool isPal(string s)
    {
        for(int i=0,j=s.length()-1; i<j;++i,--j)
        {
            if(s[i]!=s[j])
                return false;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(string &s:words)
        {
            if(isPal(s))
                return s;
        }
        return "";
    }
};