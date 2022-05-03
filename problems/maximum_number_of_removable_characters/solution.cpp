class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
       int l=0, r= removable.size()-1;
        int res=-1;
        unordered_map<int, int> mp;
        for(int i=0; i<removable.size();++i)
            mp[removable[i]]=i;
        while(l<=r)
        {
            int mid=(l+r)/2;

            int j=0;
            for(int i=0; i<s.size();++i)
            {
                if((!mp.count(i)||mp[i]>mid) && j<p.size()&&s[i]==p[j])
                    ++j;
            }
            if(j==p.size())
            {
                res=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        
        return res+1;
    }
};