class Solution {
public:
    string truncateSentence(string s, int k) {
        string res;
        int i=0;
        while(i<s.size() && k)
        {
            if(s[i]==' ')
            {
                k--;
                if(!k)
                    break;
            }
            res.push_back(s[i]);
            ++i;
        }
        return res;
    }
};