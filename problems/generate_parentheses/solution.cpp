class Solution {
public:
    
    void Dfs(int o, int i, int n,string &s, vector<string> &res)
    {
        if(i==n)
        {
            res.push_back(s);
            return;
        }
        if(o< n-i)
        {
            s.push_back('(');
            Dfs(o+1, i+1, n, s, res);
            s.pop_back();
        }
        if(o>0)
        {
            s.push_back(')');
            Dfs(o-1, i+1, n, s,res);
            s.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        string s;
        Dfs(0,0,2*n,s,res);
        return res;
    }
};