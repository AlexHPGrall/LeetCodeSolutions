class Solution {
public:
    int minDeletions(string s) {
      vector<int> freq(26,0);
        unordered_map<int, int> freqMap;
        for(char c:s)
        {
            freq[c-'a']++;
        }
        sort(freq.begin(),freq.end());
        for(int i:freq)
            freqMap[i]++;
        int res=0;
        for(int i=25;~i;--i)
        {
            
            if(freq[i]==0)
                break;
            if(freqMap[freq[i]]>1)
            {
                freqMap[freq[i]]--;
                do
                {
                    freq[i]--;
                    res++;
                }while(freq[i] && freqMap[freq[i]]);
                
                freqMap[freq[i]]=1;
                
            }
        }
        
        return res;
        
        
    }
};