class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        vector<vector<int>> pal(n,vector<int>(n,1));
        int res=1;
        int a=0,b=0;
        for(int l=2;l<=n;++l)
        {
            for(int i=0;i<=n-l;++i)
            {
                if(l==2)
                {
                    pal[i][i+1]= s[i]==s[i+1]?2:0;
                    
                }
                else
                    pal[i][i+l-1]=s[i]==s[i+l-1]&&pal[i+1][i+l-2]?pal[i+1][i+l-2]+2:0;
                if(pal[i][i+l-1]>res)
                {
                    a=i;b=i+l-1;
                    res=max(pal[i][i+l-1],res);
                }
                
            }
        }
        return s.substr(a,b-a+1);
    }
};