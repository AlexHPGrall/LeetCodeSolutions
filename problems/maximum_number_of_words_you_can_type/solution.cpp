class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int bk[26]={};
        for(char c:brokenLetters)
            bk[c-'a']=1;
        int res=1;
        int i=0;
        while(i<text.length())
        {
            //cout<<i<<endl;
            if(text[i]==' ')
            {res++;}
            else if(bk[text[i]-'a'])
            {
                res--;
                while(i<text.length() && text[i]!=' ')
                    ++i;
                continue;
            }
            ++i;
            //cout<<res<<endl;
                
        }
        return res;
    }
};