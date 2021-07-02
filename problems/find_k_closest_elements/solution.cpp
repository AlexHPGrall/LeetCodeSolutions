



struct MyPair
    {
        int index;
        int dist;
        
    };
bool operator<(const MyPair &lhs,const MyPair &rhs)
        {return (lhs.dist<rhs.dist || (lhs.dist==rhs.dist && lhs.index < rhs.index));}
class Solution {
public:
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<MyPair> pq;
        for(int i:arr)
        {
            MyPair p;
            p.index = i;
            p.dist = abs(i-x);
            pq.push_back(p);
            push_heap(pq.begin(), pq.end());
            if(pq.size() > k)
            {
                
                pop_heap(pq.begin(), pq.end());
                pq.pop_back();
                
            }
            
        }
        vector<int> res;
        for(auto p:pq)
        {
            res.push_back(p.index);
        }
        sort(res.begin(), res.end());
        return res;
    }
};