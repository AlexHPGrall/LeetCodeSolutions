class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=0, right=0;
        long long sum;
        for(int m:piles)
        {
            right=max(m,right);
            sum+=m;
        }
        left=max(1,(int)(sum/h));
        int mid;
        
        while(left<right)
        {
            int mid = left +(right-left)/2;
            int t=0;
            for(int m : piles)
            {
                t+=m/mid + (m%mid!=0);
            }
            if(t<=h)
            {
                right=mid;
                
            }
            else
            {
                left=mid+1;
            }
            
        }
        
        return left;
    }
};