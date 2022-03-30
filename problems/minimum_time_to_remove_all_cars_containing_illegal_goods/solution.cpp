class Solution {
public:
    int minimumTime(string s) {
     int sum=0;
        int dp=0;
        for(char c:s)
        {
            if(c=='1')
                sum+=1;
            else
                sum-=1;
            
            dp=min({0,sum,dp});
            sum=min(0,sum);
        }
        return s.length()+dp;
    }
};