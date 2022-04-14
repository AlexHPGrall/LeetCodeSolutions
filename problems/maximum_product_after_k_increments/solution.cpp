class Solution {
public:
    int mod=(1e9)+7;
    int maximumProduct(vector<int>& nums, int k) {
       vector<int> pq;
        for(int n:nums)
            pq.push_back(n);
        make_heap(pq.begin(), pq.end(), greater<int>{});
        while(k)
        {
            
            pop_heap(pq.begin(), pq.end(), greater<int>{});
            pq[pq.size()-1]++;
            push_heap(pq.begin(), pq.end(), greater<int>{});
            

            k--;
        }
        unsigned long long res=1;
        for(int n:pq)
            res= (res*(n%mod))%mod;
        return (int)res;
    }
};