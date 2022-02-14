class Solution {
public:
    unordered_set<string> st;
    void recPar(int k, int o, string& s)
    {
        if(k==0 && o==0)
            st.insert(s);
        if(k>0)
        {
            s.push_back('(');
            recPar(k-1,o+1,s);
            s.pop_back();
        }
        if(o>0)
        {
            s.push_back(')');
            recPar(k,o-1,s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string tmp;
        recPar(n,0,tmp);
        for(string s:st)
            res.push_back(s);
        return res;
    }
};