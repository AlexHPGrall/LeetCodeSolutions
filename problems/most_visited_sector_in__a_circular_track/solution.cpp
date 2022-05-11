class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> freq(n+1,0);
        int top=0;
        for(int i=0; i<rounds.size()-1;++i)
        {
            if(rounds[i]<rounds[i+1])
                for(int j=rounds[i]; j<rounds[i+1];j++)
                {
                    freq[j]++;
                    top=max(top,freq[j]);
                }
            else
            {
                for(int j=1; j<rounds[i+1];++j)
                 {
                    freq[j]++;
                    top=max(top,freq[j]);
                }  
                for(int j=rounds[i]; j<=n;++j)
                {
                    freq[j]++;
                    top=max(top,freq[j]);
                }  
            }
        }
        freq[rounds.back()]++;
        top=max(top,freq[rounds.back()]);
        vector<int> res;
        for(int i=1;i<freq.size();++i)
            if(freq[i]==top)
                res.push_back(i);
        return res;
        
    }
};