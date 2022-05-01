class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i=s.size()-1;
        int j=t.size()-1;
        int bcount=0;
        while(i>=0 || j>=0)
        {
            bcount=0;
            while(i>=0&&s[i]=='#')
            {
                
                while(i>=0 &&s[i]=='#')
                {--i;bcount++;}
                while(i>=0&&s[i]!='#'&&bcount)
                {
                    --i;
                    bcount--;
                }
            }
            bcount=0;
            while(j>=0 && t[j]=='#')
            {
                
                while(j>=0 && t[j]=='#')
                {--j;bcount++;}
                while(j>=0&&t[j]!='#'&&bcount)
                {
                    --j;
                    bcount--;
                }
            }
            if(i<0 && j<0)
                break;
            if((i<0 &&j>=0)||(j<0 && i>=0)||t[j]!=s[i])
                return false;
            //cout<<t[j]<<' '<<s[i]<<endl;
            i--;
            j--;
        }
        //cout<<i<<' '<<j<<endl;
        if((i<0 &&j>=0)||(j<0 && i>=0))
            return false;
        return true;
    }
};