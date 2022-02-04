class Solution {
public:
    int longestAwesome(string s) {
         unordered_map<int, int> mp;
        mp[0] =-1;
        int res=0;
        int mask=0;
        for(int i=0;i<s.length();++i)
        {
            mask^=(1<<(s[i]-'0'));
            if(mp.count(mask))
                res=max(i-mp[mask],res);
            else
                mp[mask]=i;
            for(int j=0;j<10;++j)
            {
                if(mp.count(mask^(1<<j)))
                {
                    res=max(i-mp[mask^(1<<j)],res);
                }
            }
            
        }
       
        return res;
    }
};