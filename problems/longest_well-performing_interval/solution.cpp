class Solution {
public:

    int longestWPI(vector<int>& h) {
        unordered_map<int ,int> mp;
        vector<int> len(h.size(),0);
        mp[0]=-1;
        int sum=0;
        int res=0;
        for(int i=0;i<h.size();++i)
        {
            if(h[i]>8)
                sum+=1;
            else
                sum-=1;
            if(mp.count(sum-1))
            {
                int j=mp[sum-1];
                len[i]=i-j;
                if(j>=0)
                    len[i]+=len[j];
            }
            if(!mp.count(sum))
            {
                mp[sum]=i;
            }
            res=max(res,len[i]);
        }

        return res;
    }
};