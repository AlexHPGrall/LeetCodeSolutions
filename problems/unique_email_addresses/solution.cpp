class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int  res=0;
        unordered_set<string> mailSet;
        for(string &address:emails)
        {
            string s;
            
            int i=0;
            for(i=0;address[i]!='@';++i)
            {
                if(address[i]=='.')
                    continue;
                if(address[i]=='+')
                    break;
                s.push_back(address[i]);
            }
            while(address[i]!='@')
                ++i;
            for(;i<address.size();++i)
                s.push_back(address[i]);
            if(!mailSet.count(s))
            {
                mailSet.insert(s);
                res++;
            }
        }
        return res;
    }
};