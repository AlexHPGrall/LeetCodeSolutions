class KthLargest {
    vector<int> heap;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        heap=nums;
        this->k=k;
        
        make_heap(heap.begin(), heap.end(), std::greater<>{});
        while(heap.size()>k)
        {
            pop_heap(heap.begin(), heap.end(), std::greater<>{});
            heap.pop_back();
        }
      
    }
    
    int add(int val) {

            heap.push_back(val);
            push_heap(heap.begin(), heap.end(), std::greater<>{});
        
        if(heap.size()>k)
        {
            pop_heap(heap.begin(), heap.end(), std::greater<>{});
            heap.pop_back();
            
        }
        return heap[0];
    }
};
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */