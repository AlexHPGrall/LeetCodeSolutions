class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(), time.end());
        long long r=(long long)totalTrips*(long long)time[0];
        long long l=0;
        while(l<=r)
        {
            long long mid=l+(r-l)/2;
            long long curr=0;
            for(int n:time)
            {
                curr+=mid/n;
                if(curr>=totalTrips)
                    break;
            }
            if(curr>=totalTrips)
                r=mid-1;
            else
                l=mid+1;
        }
        return l;
        
    }
};