class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> DPTable;
        int maxl=1;
        sort(words.begin(), words.end(), 
        [](const string& s1, const string& s2){return s1.length()>s2.length();});
        for(string s: words)
            DPTable.emplace(s,1);
        for(string s:words)
        {
            int n = s.length();
            for(int i=0; i<n; ++i)
            {
                string s2;
                for(int j=0; j<n; ++j)
                {
                    if(j==i)
                        continue;
                    s2.push_back(s[j]);
                }
                if(DPTable.find(s2) == DPTable.end())
                    continue;
                else
                {
                    DPTable[s2] = max(DPTable[s2], DPTable[s] +1);
                    maxl= max(maxl, DPTable[s2]);
                }
                
            }
            
        }
        
        return maxl;
    }
   
};