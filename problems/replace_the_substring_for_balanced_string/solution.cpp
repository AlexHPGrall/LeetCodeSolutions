class Solution {
public:
    int balancedString(string s) {
        int n=s.size();
        int k=n/4;
        unordered_map<char, int> mp;
        for(char c:s)
        {
            mp[c]++;
        }
        mp['E']-=k;mp['Q']-=k;mp['W']-=k;mp['R']-=k;
        if(!mp['E']&&!mp['Q']&&!mp['W']&&!mp['R'])
            return 0;
        int i=0, j=0;
        int res=s.size();
        unordered_map<char, int> run;
        run[s[0]]++;
        if(mp['E']<=run['E']&&mp['Q']<=run['Q']
           &&mp['W']<=run['W']&&mp['R']<=run['R'])
            res=min(res, j-i+1);
        //cout<<m<<' '<<t<<endl;
        while(i<=j)
        {
            //cout<<i<<' '<<j<<endl;
            if(j<s.size()-1&&!(mp['E']<=run['E']&&mp['Q']<=run['Q']
           &&mp['W']<=run['W']&&mp['R']<=run['R']))
            {
                ++j;
                run[s[j]]++;
                 if(mp['E']<=run['E']&&mp['Q']<=run['Q']
                    &&mp['W']<=run['W']&&mp['R']<=run['R'])
                        res=min(res, j-i+1);
            }
            else if(i!=j)
            {
                ++i;
                run[s[i-1]]--;
                if(mp['E']<=run['E']&&mp['Q']<=run['Q']
                    &&mp['W']<=run['W']&&mp['R']<=run['R'])
                        res=min(res, j-i+1);
            }
            else
                break;
        }
        return res;
        
    }
};