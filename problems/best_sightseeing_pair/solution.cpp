class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int currmax=values[0];
        
        
        int res=0;
        for(int i=0, j=1; j<values.size();++j)
        {
            res=max(res,currmax+values[j] + i-j);
            if(values[j]>=(currmax+i-j))
            {
                i=j;
                currmax=values[j];
            }
        }
        return res;
    }
};