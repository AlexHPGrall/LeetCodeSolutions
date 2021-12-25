class Solution {
public:
    int i;
    int eval(string &s)
    {
            while(s[i]==' ')
            {
                ++i;
            }
            int ttmp=0;
            while(s[i]>='0' && s[i]<='9')
            {
                ttmp *=10;
                ttmp+=(s[i]-'0');
                ++i;
            }
             while(s[i]==' ')
            {
                ++i;
            }
        return ttmp;
    }
    int calculate(string s) {
        int res=0;
        char op='+';
        i=0;
        while(i<s.length())
        {
            int tmp=eval(s);
            
            while(i<s.length()&&(s[i]=='*' || s[i] =='/'))
            {
                
                if(s[i++] == '*')
                    tmp=tmp*eval(s);
                else
                    tmp=tmp/eval(s);
            }
            if(op =='+')
                res +=tmp;
            else
                res=res-tmp;
            if(i<s.length())
                op=s[i++];         
        }
            
        return res;
    }
};