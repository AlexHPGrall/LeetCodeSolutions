class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int res=0;
        for(string &w:words)
        {
            for(int i=0;i<w.size();++i)
            {
                if(i>=s.size() || s[i]!=w[i])
                {  res--;break;}
            }
            res++;
        }
        return res;
    }
};