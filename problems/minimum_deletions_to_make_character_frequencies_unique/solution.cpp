class Solution {
public:
    int minDeletions(string s) {
      int freq[26]={0};
        for(char c:s)
        {
            freq[c-'a']++;
        }
        map<int, int> mp;
        
        for(int i=0; i<26;++i)
        {
            if(freq[i]>0)
            mp[freq[i]]++;
        }
        int res=0;
        for(auto it=mp.rbegin();it!=mp.rend();++it)
        {
            if(it->first==0)
                break;
            
            if(it->second>1)
            {
                res+=it->second-1;
                mp[it->first-1]+=it->second-1;
            }
        }
        return res;
        
        
    }
};