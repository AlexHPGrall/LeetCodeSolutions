struct info
{
  string str;
  int index;
};

class Solution {
public:

    info recDecode(string &s, int start=0)
    {
        int rep=0;
        info res={};
        res.str="";
        for(int i =start;i<s.length();++i)
        {
            while(s[i]<='9' && s[i]>='0')
            {
              rep=rep*10 +s[i]-'0';
              ++i;
            }
            if(rep != 0)
            {
                info tres=recDecode(s, i+1);
                while(rep)
                {
                     res.str+=tres.str;
                     rep--;
                }
                i=tres.index -1;
                continue;
            }
            if(s[i]==']')
            {
                res.index = i+1;
                return res;
            }
            if(s[i]>='a' && s[i]<='z')
            {
                res.str +=s[i];
            }
    
        }
        return res;
    }
    string decodeString(string s, int i=0) {
        info res=recDecode(s);
        return res.str;
        
    }
};