class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int res=0;
        int curr=rungs.back();
        for(int i=rungs.size()-1; i>0;)
        {
            if(curr-rungs[i-1]>dist)
            {
                res+=(curr-rungs[i-1]-1)/dist;
            }
            --i;
            curr=rungs[i];
        }
        if(curr>dist)
            res+=(curr-1)/dist;
        return res;
    }
};