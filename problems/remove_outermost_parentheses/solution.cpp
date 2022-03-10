class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int sum=1;
        for(int i=1;i<s.length();++i)
        {
            if(s[i]=='(')
                sum++;
            else
                sum--;
            if(sum==0)
            {
                sum=1;
                ++i;
            }
            else
                res.push_back(s[i]);
        }
        return res;
    }
};