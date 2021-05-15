class Solution {
public:
    bool isNumber(string s) {
        int n=s.length();
        bool exp, dec;
        exp = dec=false;
        if(n == 0)
            return false;
        for(int i =0; i<n; ++i)
        {
            if(s[i] != 'e' && s[i]>='a' && s[i]<='z')
                return false;
            if(s[i] != 'E' && s[i]>='A' && s[i]<='Z')
                return false;
            switch(s[i])
            {
                case '+':
                case '-':
                    {
                        if(i != 0 && s[i-1] != 'e' && s[i-1] !='E')
                            return false;
                        if(i == n-1)
                            return false;
                        break;
                    }
                case 'e':
                case 'E':
                    {
                        if(exp || i == 0 || i==n-1)
                            return false;
                        if(i==1 && (s[0] == '+' || s[0] == '-') )
                            return false;
                        exp =true;
                        break;
                    }
                case '.':
                    {
                        if(dec || exp || (i==n-1 && n == 1) )
                            return false;
                        if(i >0  && i < n-1 && n > 2 && !(s[i-1] >= '0' && s[i-1]<='9') && !(s[i+1] >= '0' && s[i+1]<='9'))
                            return false;
                        if(i ==0  && n > 1 && !(s[i+1] >= '0' && s[i+1]<='9'))
                            return false;
                        if(i == n-1 && n > 1 && !(s[i-1] >= '0' && s[i-1]<='9') )
                            return false;
                        dec= true;
                        break;
                    }
            }
            
        }
        return true;
        
    }
};