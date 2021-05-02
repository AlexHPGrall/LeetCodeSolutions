class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](auto &a, auto &b){return a[1]<b[1];});
        priority_queue<int> pq;
        int total =0;
        for(auto u:courses)
        {
            int dur = u[0], end = u[1];
            if(total + dur<= end)
            {
                pq.push(dur);
                total+=dur;
            }
            else if(pq.size() && dur < pq.top())
            {
                total += dur-pq.top();
                pq.pop();
                pq.push(dur);
            }
        }
        return pq.size();
        
    }
};