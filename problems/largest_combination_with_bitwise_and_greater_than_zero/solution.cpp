class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> bitMap(32);
        for(int can:candidates)
        {
            for(int i=0;i<32;++i)
                if(can&(1<<i))
                    bitMap[i]++;
        }
        int res=0;
        for(int n:bitMap)
        {
            res=max(res,n);
        }
        return res;
    }
};