class Solution {
public:
    bool isPossible(vector<int>& target) {
        if(target.size()==1)
            return target[0]==1;
        priority_queue<int> pq;
        long long sum=0;
        
        for(int n:target)
        {
            pq.push(n);
            sum+=n;
        }
        sum-=pq.top();
        while(pq.top()!=1)
        {
            int x=pq.top();
            if(x-sum<1)
                return false;
            x%=sum;
            if(x==0)
                x+=sum;
            pq.pop();
            
            pq.push(x);
            sum+=x;
            sum-=pq.top();
        }
        
        return true;
    }
};