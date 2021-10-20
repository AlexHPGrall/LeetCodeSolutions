class Solution {
public:
    void reverseWord(string &s, int l, int r)
    {
        while(l<r)
        {
            char t= s[l];
            s[l++]=s[r];
            s[r--] = t;
        }
    }
    string reverseWords(string s) {
        int i=0;
        int j=0;
        int wc=0;
        int n= s.length();
        for(;;)
        {
            while(i<n && s[i] == ' '){++i;}
            if(i==n)
                break;
            if(wc)
                s[j++] =' ';
            int l=j;
            while(i<n && s[i]!=' ')
                s[j++] = s[i++];
            reverseWord(s, l, j-1);
            wc++;
        }
        s.resize(j);
        reverseWord(s,0,j-1);
        return s;
    }
};