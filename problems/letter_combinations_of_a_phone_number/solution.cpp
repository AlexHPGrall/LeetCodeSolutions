class Solution {
public:
    vector<string> charMap={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void dfs(vector<string> &res, string &dig, string &curr, int index)
    {
        if(index==dig.size())
        {
            res.push_back(curr);
            return;
        }
        for(char c:charMap[dig[index]-'0'])
        {
            curr.push_back(c);
            dfs(res,dig,curr,index+1);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size()==0)
            return res;
        string s="";
        dfs(res,digits,s,0);
        return res;
    }
};