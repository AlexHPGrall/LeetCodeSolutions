class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        int n=stones.size();
        priority_queue<int> pq;
        for(int i:stones)
            pq.push(i);
        while(pq.size()>=2)
        {
            int s1=pq.top();
            pq.pop();
            int s2=pq.top();
            pq.pop();
            pq.push(s1-s2);
        }
        return pq.empty()?0:pq.top();
        
    }
};