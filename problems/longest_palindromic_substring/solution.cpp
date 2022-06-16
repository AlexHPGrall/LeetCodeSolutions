class Solution {
public:
    string longestPalindrome(string s) {
        string t;
        for(char c:s)
        {t+="#";
         t+=c;
        }
        t+="#";
        int n=t.size();
        t="$"+t+"^";
        int l=1;
        int r=1;
        int resIndex=1;
        int resLength=1;
        vector<int> d(n+2);
        for(int i=1; i<=n;++i)
        {
            d[i]=max(0, min(r-i, d[l+r-i]));
            while(t[i+d[i]]==t[i-d[i]])
                ++d[i];
            if(i+d[i]>r)
            {
                l=i-d[i];
                r=i+d[i];
            }
            if(resLength<d[i])
            {
                resLength=d[i];
                resIndex=i;
            }
           
        }
  
        string res;
        for(int i=resIndex-d[resIndex]+1;i<resIndex+d[resIndex];++i)
        {
            if(t[i]!='#')
                res.push_back(t[i]);
        }
        return res;
    }
};