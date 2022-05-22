class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<bool>> pal(n, vector<bool>(n,false));
        int res=0;
        for(int sz=0; sz<n;++sz)
        {
            for(int i=0, j=sz;j<n;++i,++j)
            {
                if(sz==0)
                {
                    pal[i][j]=true;
                }
                else if(sz==1)
                {
                    pal[i][j]=s[i]==s[j];
                }
                else
                {
                    pal[i][j]=(pal[i+1][j-1]&&(s[i]==s[j]));
                }
                if(pal[i][j])
                    res++;
            }
        }
        return res;
    }
};