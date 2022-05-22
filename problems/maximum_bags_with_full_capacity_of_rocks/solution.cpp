class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> rem;
        int n=capacity.size();
        for(int i=0; i<n;++i)
        {
            rem.push_back(capacity[i]-rocks[i]);
        }
        int res=0;
        sort(rem.begin(), rem.end());
        for(int i=0; i<n;++i)
        {
            if(additionalRocks<rem[i])
                break;
            additionalRocks-=rem[i];
            ++res;
            
        }
        return res;
    }
};