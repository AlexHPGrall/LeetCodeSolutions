class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int r) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int curr=0;
        for(int i=1; i<h.size();++i)
        {
            if(h[i]>h[i-1])
                pq.push(h[i]-h[i-1]);
            if(pq.size()>r)
            {
               curr+=pq.top(); 
                pq.pop();
                if(curr>b)
                    return i-1;
            }
            //cout<<curr<<endl;
        }
        
        return h.size()-1;
        
    }
};