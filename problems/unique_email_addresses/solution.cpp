class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> unq;
        int res=0;
        for(string s:emails)
        {
            string w;
            bool plus=false;
            int i=0;
            for(i=0;i<s.length()&&s[i]!='@';++i)
            {
                if(plus)
                    continue;
                if(s[i]=='+')
                    plus=true;
                else if(s[i]!='.')
                {
                    w.push_back(s[i]);
                }
            }
            w+=s.substr(i);
            if(!unq.count(w))
            {
                //cout<<w<<endl;
                res++;
                unq.insert(w);
            }
        }
        
        return res;
    }
};