class Solution {
public:
    int eval(string &s, int l, int r)
    {
        int a=0;
        int b=0;
        int c=0;
        int i=0;
        while(i<=l)
        {
            a*=10;
            a+=s[i]-'0';
            ++i;
        }
        int tmp=0;
        while(i<=r)
        {
            if(s[i]=='+')
            {
                tmp=b;
                b=0;
                ++i;
                continue;
            }
            b*=10;
            b+=s[i]-'0';
            ++i;
            
        }
        b+=tmp;
        while(i<s.size())
        {
            c*=10;
            c+=s[i]-'0';
            ++i;
        }
        if(l==-1)
            a=1;
        if(r==s.size()-1)
           c=1; 
        return a*b*c;
    }
    
    string minimizeResult(string exp) {
        int n=exp.size();
        int cmin=INT_MAX;
        int p=0;
        int l;
        int r;
        for(int i=0; i<n;++i)
            if(exp[i]=='+')
                p=i;
        for(int i=-1; i<p-1;++i)
            for(int j=p+1; j<n;++j)
            {
                int loc=eval(exp,i,j);
                if(loc<cmin)
                {cmin=loc; l=i;r=j;}
            }
        string res;
        int i=0;
        while(i<=l)
            res.push_back(exp[i++]);
        res.push_back('(');
        while(i<=r)
            res.push_back(exp[i++]);
        res.push_back(')');
        while(i<exp.size())
            res.push_back(exp[i++]);
        return res;
    }
};