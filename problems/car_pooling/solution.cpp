class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> stops(1001,0);
        int mxstop =-1;
        for(auto data : trips)
        {
            stops[data[1]] +=data[0];
            stops[data[2]] -=data[0];
            mxstop = max({mxstop,data[1],data[2]});
        }
        int acc=0;
        for(int i=0;i<=mxstop;++i)
        {
            acc +=stops[i];
            if(acc > capacity)
                return false;
        }
        return true;
            
    }
};