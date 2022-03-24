class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum=0.0f;
        double tg;
        int res=0;
        priority_queue<double> pq;
        for(int n:nums)
        {
            sum+=n;
            pq.push((double)n);
            
        }
        tg=sum/2.0f;
        while(sum>tg)
        {
            double d=pq.top();
            pq.pop();
            sum-=(d/2.0f);
            res++;
            pq.push(d/2.0f);
        }
        
        return res;
    }
};