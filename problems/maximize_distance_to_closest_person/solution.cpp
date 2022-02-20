class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n =seats.size();
        int currmax=0;
        int l=0,r=n-1;
        while(seats[l]==0)
        {
            ++l;
        }
        currmax=l;
        while(seats[r]==0)
        {
            --r;
        }
        currmax=max(currmax, (n-1-r));
        
        for(int i=l;i<r;++i)
        {
            if(seats[i])
                continue;
            int j=i;
            while(i<r && seats[i]==0)
            {
                ++i;
            }
            currmax=max(currmax,(int) ceil((float)(i-j)/2.0f));
        }
        
        return currmax;
        
    }
};