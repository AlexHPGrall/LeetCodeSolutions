class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int currcount=0;
        int n=s.length();
        int charcnt=0;
        for(int i=0;i<n;++i)
        {
            if(s[i]!='-')
                charcnt++;
        }
        if(!charcnt)
            return "";
        int dashcount=(charcnt/k);
        if(charcnt%k==0)
            dashcount-=1;
        string res;
        res.resize(charcnt+dashcount);
        //cout<<charcnt+dashcount<<endl;
        for(int i=res.size()-1, j=n-1;i>=0;j--,i--)
        {
            //cout<<i<<" "<<j<<endl;
            while(s[j]=='-')
                --j;
            res[i]=s[j]>='a'?s[j]-'a'+'A':s[j];
            currcount++;
            if(currcount==k)
            {
                currcount=0;
                i--;
                if(i>=0)
                    res[i]='-';
            }
            
        }
        return res;
    }
};