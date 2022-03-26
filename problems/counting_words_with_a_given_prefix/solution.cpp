class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int res=0;
        for(string &w:words)
        {
            res++;
            for(int i=0;i<pref.size();++i)
            {
                if(i>w.size()||w[i]!=pref[i])
                {res--;break;}
            }
        }
        return res;
    }
};