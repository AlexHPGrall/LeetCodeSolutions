class Solution {
public:
    bool isPalindrome(string s) {
        string t;
        for(char c:s)
        {
            if(c>='A' && c<='Z')
            {
                t.push_back(c-'A'+'a');
            }
            else if(c>='a' && c<='z')
                t.push_back(c);
            else if(c>='0' && c<='9')
                t.push_back(c);
        }
        int i=0;
        int j=t.size()-1;
        while(i<j)
        {
            if(t[i]!=t[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }
};