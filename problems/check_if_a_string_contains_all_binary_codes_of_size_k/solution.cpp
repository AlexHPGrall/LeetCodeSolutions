class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k>=s.size())
            return false;
        unordered_set<int> binCodes;
        int curr=0;
        for(int i=0; i<k;++i)
        {
            if(s[i]=='1')
                curr+=(1<<i);
        }
        
        binCodes.insert(curr);
        for(int i=k; i<s.size();++i)
        {
            curr>>=1;
           
            if(s[i]=='1')
                curr+=(1<<(k-1));
            
            binCodes.insert(curr);
        }
        
        return binCodes.size()==(1<<k);
    }
};