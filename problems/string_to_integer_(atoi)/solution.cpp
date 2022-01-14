class Solution {
public:
    string maxint={"2147483648"};
    int myAtoi(string s) {
        int l=s.length();
        int i=0;
        int res=0;
        bool minus=false;
        while(i<l && s[i]==' ')
            ++i;
        if(i<l && (s[i] =='-' || s[i] =='+'))
        {
            if(s[i]=='-')
                minus=true;
            ++i;
        }
        
        int dc=0;
        bool gt=false;
        bool eq=true;
        while(i<l && s[i]=='0')
            ++i;
        while(i<l && s[i]>='0' && s[i]<='9')
        {
            ++dc;
            
            if(dc >10)
            {
                if(minus)
                    res=INT_MIN;
                else
                    res=INT_MAX;
                return res;
            }
            if(s[i]>maxint[dc-1] && eq)
                gt=true;
            else if(s[i]<maxint[dc-1])
                eq =false;
            
            if(dc == 10 && (gt || eq) )
            {
                if(minus)
                    res=INT_MIN;
                else
                    res=INT_MAX;
                return res;
            }
            res=res*10 +(s[i]-'0');
            ++i;
        }
        if(minus)
            res=-res;
        return res;
            
    }
};