class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n =seats.size();
        int start=0;
        int currdist=0;
        int res=0;
        while(start<n && seats[start]!=1)
        {
            start++;
        }
            
        res=max(0,start);
        for(int i =start; i< n;++i)
        {
             if(seats[i])
             {
                 res=max(res, (currdist+1)/2);
                 currdist =0;
             }
                 
            else
                currdist++;
        }
        res=max(res, currdist);
        
        return res;
    }
};