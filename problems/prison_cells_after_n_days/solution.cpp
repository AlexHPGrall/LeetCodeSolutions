class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        static vector<int> dp(256,-1);
        if(dp[0]==-1)
        {
            for(int i=0;i<256;++i)
            {
                int mask=0;
                for(int j=1;j<7;++j)
                {
                    if((i&(1<<(j-1)) && i&(1<<j+1) )||(!(i&(1<<(j-1))) && !(i&(1<<(j+1)))))
                        mask |=(1<<j);
                }
                dp[i] = mask;
            }
        }
        if(n==0)
            return cells;
        int cycleLength=0;
        int cycleStart;
        unordered_map<int,int> mp;
        vector<int> cycle(256);
        int cindex=1;
        int state=0;
        for(int i=0;i<8;++i)
        {
            if(cells[i])
                state|=(1<<i);
        }
        cycle[0]=state;
        for(;cindex<=n&&cindex<256;)
        {
            state=dp[state];
            cycle[cindex]=state;
            if(mp.count(state))
            {
                cycleStart=mp[state];
                cycleLength=cindex-mp[state];
                break;
            }
            else
            {
                mp[state]=cindex;
                cindex++;
            }
        }
        int resState=0;
        if(cindex==n+1)
            resState= cycle[n];
        else
        {
            cindex=(n-cycleStart)%cycleLength;
            resState= cycle[cindex+cycleStart];
        }
        //cout<<cycleLength<<" "<<cycleStart<<endl;
        vector<int> res(8,0);
        for(int i=0;i<8;++i)
        {
            if(resState&(1<<i))
                res[i]=1;
        }
        return res;
    }
};