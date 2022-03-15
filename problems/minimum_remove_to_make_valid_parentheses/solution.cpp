class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> op,close;
        for(int i=0;i<s.length();++i)
        {
            if(s[i]=='(')
                op.push_back(i);
            if(s[i]==')')
                if(!op.empty())
                    op.pop_back();
                else
                    close.push_back(i);
        }
        string res;
        int k=0,l=0;
        for(int i=0;i<s.length();++i)
        {
            if(k<op.size() && op[k]==i)
            {++k;continue;}
            if(l<close.size() && close[l]==i)
            {++l;continue;}
            res.push_back(s[i]);
        }
        return res;
    }
};