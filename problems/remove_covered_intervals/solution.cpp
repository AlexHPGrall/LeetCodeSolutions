class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int first=intervals[0][0];
        int last=intervals[0][1];
        int n=intervals.size();
        int res=n;
        for(int i =1;i<n; ++i)
        {
            if(intervals[i][1]<=last)
                res--;
            else if(intervals[i][0] == first)
            {res--; last=intervals[i][1];}
            else
            {first=intervals[i][0];last=intervals[i][1];}
        }
        return res;
    }
};