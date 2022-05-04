class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int res=0;
        for(int n:nums)
            freq[n]++;
        for(auto& [key,f]:freq)
        {   
            
            
            if(2*key != k)
            {
                if(freq.count(k-key))
                    res+=min(f, freq[k-key]);
            }
            else
                res+=(f/2);
            
            f=0;
            
        }
        return res;
    }
};