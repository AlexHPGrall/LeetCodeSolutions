class Solution {
public:
    string largestGoodInteger(string s) {
        string res="";
        char maxC='0'-1;
        for(int i=0; i<s.size()-2;++i)
        {
            if(s[i]==s[i+1]&&s[i]==s[i+2])
                maxC=(char)max((int)s[i],(int)maxC);
        }
        if(maxC>='0')
            for(int i=0;i<3;++i)
                res.push_back(maxC);
        return res;
    }
};