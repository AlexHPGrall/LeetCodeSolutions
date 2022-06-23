class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(begin(courses), end(courses), [](const vector<int> &a, const vector<int> &b)
             {
                 if(a[1]==b[1])
                     return a[0]<b[0];
                 return a[1]<b[1];
             });
        priority_queue<int> pq;
        int end=0;
        for(auto &v:courses)
        {
            if(v[0]+end<=v[1])
            {
                end+=v[0];
                pq.push(v[0]);
            }
            else
            {
                if(!pq.empty() && pq.top()> v[0])
                {
                    end+=v[0]-pq.top();
                    pq.pop();
                    pq.push(v[0]);
                }
                
            }
        
        }
        return pq.size();
        
    }
};