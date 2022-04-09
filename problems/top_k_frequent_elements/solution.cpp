class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        // count frequencies
        unordered_map<int, int> numFreq;
        int maxFreq = 0;
        for(int num : nums)
        {
            numFreq[num]++;
            maxFreq = max(maxFreq, numFreq[num]);
        }
        
        // reverse previous hash, ie store elements into buckets (frequencies)
        unordered_map<int, vector<int>> freqNum;
        for(auto curr : numFreq)
            freqNum[curr.second].push_back(curr.first);
        
        // start from maxFreq and find first k-max freqs
        // since there is at most N elements to check 
        // (when considering bucket - numbers config)
        // time complexity (as well as space) is O(N)
        int currFreq = maxFreq;
        int foundSoFar = 0;
        vector<int> res;
        while(foundSoFar < k)
        {
            if(freqNum.count(currFreq))
            {
                res.insert(res.end(), freqNum[currFreq].begin(), freqNum[currFreq].end());
                foundSoFar += freqNum[currFreq].size();
            }
            
            currFreq--;
        }
        
        return res;
    }
};