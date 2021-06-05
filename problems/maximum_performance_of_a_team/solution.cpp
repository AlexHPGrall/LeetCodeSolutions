class Solution {
public:
  
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> emp;
        for(int i =0; i<n; ++i)
        {
            emp.push_back({efficiency[i], speed[i]});
        }
        sort(emp.rbegin(), emp.rend());
        priority_queue<int> pq;
        long best =0, sumspeed =0;
        for(int i= 0; i<n; ++i)
        {
            pair<int,int> p = emp[i];
            pq.push(-p.second);
            sumspeed+= p.second;
            if(i>=k)
            {
                sumspeed += pq.top();
                pq.pop();
            }
            best = max(best, sumspeed*p.first);
        }
        
        
        return best%(1000000007);
    }
    
    
};