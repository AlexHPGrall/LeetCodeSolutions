class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(begin(boxTypes), end(boxTypes), [](const auto &a, const auto &b){
            return a[1]<b[1];
        });
        int res=0;
        auto it= boxTypes.rbegin();
        while(truckSize>0 && it!=boxTypes.rend())
        {
            res+=(*it)[1]*min(truckSize,(*it)[0]);
            truckSize-=min(truckSize, (*it)[0]);
            ++it;
        }
        return res;
    }
};