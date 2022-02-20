class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int res=n;
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
             {
                 return a[0]<b[0]?true:a[0]==b[0]?b[1]<a[1]:false;
             });
        
        int currmax=intervals[0][1];
        for(int i=1; i<n;++i)
        {
            if(intervals[i][1]<=currmax)
                res--;
            else
            {
                currmax=intervals[i][1];
            }
        }
        
        return res;
    }
};