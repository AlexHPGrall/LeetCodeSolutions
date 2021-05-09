class Solution {
public:
    bool isPossible(vector<int>& target) {
        
        int m = target.size();
        if(m <=1)
            return (m ==1 && target[0] ==1);
       
        int res = 0;
        long sum =0;
        priority_queue<int> pq(target.begin(), target.end());
        for(int n:target)
            {
                sum+=n;
                
            }
        for(;;)
        {
            
           
            res =  pq.top();
            
            if(res ==1)
                return true;
            
            
                
            sum -=res;
            if(sum ==1)
                return true;
            if(res-sum <1)
                return false;
            if(res%sum ==0)
                return false;
            pq.pop();
            pq.push(res%sum);
            sum += res%sum;
            
        }
        
        return false;
        
    }
};