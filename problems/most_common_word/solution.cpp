class Solution {
public:
    string syn="!?',;. ";
    bool isSyn(char c)
    {
        for(char d:syn)
        {
            if(c==d)
                return true;
        }
        return false;
    }
    string mostCommonWord(string par, vector<string>& banned) {
       unordered_map<string,int> b,freq;
        string res="";
        for(string &s: banned)
        {
            b[s]=1;
        }
        for(int i=0;i<par.size();)
        {
            string s;
            while(i<par.size()&&!isSyn(par[i]))
            {
                if(par[i]<'a')
                    s.push_back(par[i]-'A'+'a');
                else
                    s.push_back(par[i]);
                ++i;
            }
            if(!s.empty()&& !b.count(s))
            {
                freq[s]++;
                if(freq[s]>freq[res])
                    res=s;
            }
            while(i<par.size()&&isSyn(par[i]))
                ++i;
        }
        return res;
    }
};