class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        for(string s:emails)
        {
            int i;
            bool ignore=false;
            string address;
            for(i=0;s[i]!='@';++i)
            {
                if(s[i]=='+')
                {
                    ignore = true;
                    continue;
                }
                if(ignore)
                    continue;
                
                if(s[i]!='.')
                    address.push_back(s[i]);
            }
            st.insert(address+s.substr(i));
        }
        
        return st.size();
        
    }
};