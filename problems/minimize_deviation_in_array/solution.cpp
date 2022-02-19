class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int mn = INT_MAX;
        for(int n:nums)
        {
            if(n%2)
                n*=2;
            mn=min(n,mn);
            pq.push(n);
            
        }
       
        
        int mx= pq.top();
        
        int res=mx-mn;
       
        while(mx%2==0)
        {

            mx=pq.top()>>1;
            pq.pop();
            
            pq.push(mx);

            mn = min(mn, mx);
            mx= pq.top();
            res=min(mx-mn,res);
                       
            //cout<<mn<<" "<<mx<<endl;
        }

        
        
        return res;
    }
};