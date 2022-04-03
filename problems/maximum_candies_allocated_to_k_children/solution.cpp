class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum=0;
        int mn=1e7+1;
        for(int c:candies)
        {sum+=c; mn=min(mn, c);}
        if(sum<k)
            return 0;
        int l=1;
        int r=(int)(sum/k);
        while(l<=r)
        {
            //cout<<l<<' '<<r<<endl;
            int mid =l+(r-l)/2;
            sum=0;
            for(int c:candies)
                sum+=(c/mid);
            //cout<<sum<<endl;
            if(sum<k)
                r=mid-1;
            else
                l=mid+1;
        }
    
        return r;
        
    }
};